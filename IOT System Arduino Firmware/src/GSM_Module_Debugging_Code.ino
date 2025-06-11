//#include <Serial3.h>

//Serial3 Serial3(2, 3);  // RX=Pin 3, TX=Pin 2

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);

  Serial.println(F("Initializing Serial3..."));
  delay(2000);

  // 1. Check if Serial3 is responding
  if (!sendATCommand(F("AT"), F("OK"), 2000)) {
    Serial.println(F("Serial3 not responding! Check wiring/power."));
    while (1);
  }

  // 2. Check SIM card status
  if (!sendATCommand(F("AT+CPIN?"), F("READY"), 2000)) {
    Serial.println(F("SIM card error! Check if inserted properly."));
    while (1);
  }

  // 3. Check network registration
  if (!checkNetworkRegistration()) {
    Serial.println(F("Failed to register on network!"));
    while (1);
  }

  // 4. Check signal strength (should be >10)
  checkSignalStrength();

  // 5. Configure GPRS with APN (replace with your carrier's APN)
  if (!setupGPRS(F("internet"), F("airtel"), F(""))) {
    Serial.println(F("GPRS configuration failed! Check APN settings."));
    while (1);
  }

  Serial.println(F("Serial3 Ready!"));
}

void loop() {
  // Fetch data from a test HTTP site
  fetchWebData(F("http://httpbin.org/get"));
  delay(30000);
}

// ========== CORE FUNCTIONS ==========

bool sendATCommand(const String& cmd, const String& expectedResp, unsigned long timeout) {
  Serial3.println(cmd);
  Serial.print(F("Sent: "));
  Serial.println(cmd);

  unsigned long startTime = millis();
  String response = "";

  while (millis() - startTime < timeout) {
    while (Serial3.available()) {
      char c = Serial3.read();
      response += c;
      if (response.indexOf(expectedResp) != -1) {
        Serial.print(F("Received: "));
        Serial.println(response);
        return true;
      }
    }
  }

  Serial.print(F("Timeout! Received: "));
  Serial.println(response);
  return false;
}

bool checkNetworkRegistration() {
  Serial.println(F("Checking network registration..."));

  for (int i = 0; i < 10; i++) {
    String response;
    Serial3.println(F("AT+CREG?"));
    delay(1000);
    
    while (Serial3.available()) {
      char c = Serial3.read();
      response += c;
    }

    if (response.indexOf(F("+CREG: 0,1")) != -1 || response.indexOf(F("+CREG: 0,5")) != -1) {
      Serial.println(F("Registered to network!"));
      return true;
    }
    
    delay(2000);
  }
  
  return false;
}

void checkSignalStrength() {
  Serial.println(F("Checking signal strength..."));
  sendATCommand(F("AT+CSQ"), F("OK"), 2000);
}

bool setupGPRS(const String& apn, const String& user, const String& pwd) {
  Serial.println(F("Configuring GPRS..."));

  // 1. Set connection type to GPRS
  if (!sendATCommand(F("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\""), F("OK"), 2000)) return false;

  // 2. Set APN (using regular String concatenation)
  String apnCmd = F("AT+SAPBR=3,1,\"APN\",\"");
  apnCmd += apn;
  apnCmd += F("\"");
  if (!sendATCommand(apnCmd, F("OK"), 2000)) return false;

  // 3. Set username/password if required
  if (user.length() > 0) {
    String userCmd = F("AT+SAPBR=3,1,\"USER\",\"");
    userCmd += user;
    userCmd += F("\"");
    if (!sendATCommand(userCmd, F("OK"), 2000)) return false;
  }

  if (pwd.length() > 0) {
    String pwdCmd = F("AT+SAPBR=3,1,\"PWD\",\"");
    pwdCmd += pwd;
    pwdCmd += F("\"");
    if (!sendATCommand(pwdCmd, F("OK"), 2000)) return false;
  }

  // 4. Attach to GPRS service
  if (!sendATCommand(F("AT+CGATT=1"), F("OK"), 10000)) {
    Serial.println(F("GPRS attach failed!"));
    return false;
  }

  // 5. Activate bearer profile
  for (int i = 0; i < 3; i++) {
    if (sendATCommand(F("AT+SAPBR=1,1"), F("OK"), 10000)) {
      Serial.println(F("GPRS connected!"));
      return true;
    }
    delay(2000);
  }

  Serial.println(F("Bearer activation failed!"));
  return false;
}

void fetchWebData(const String& url) {
  Serial.print(F("Fetching: "));
  Serial.println(url);

  // 1. Initialize HTTP service
  if (!sendATCommand(F("AT+HTTPINIT"), F("OK"), 2000)) return;

  // 2. Set CID
  if (!sendATCommand(F("AT+HTTPPARA=\"CID\",1"), F("OK"), 2000)) return;

  // 3. Set URL
  String urlCmd = F("AT+HTTPPARA=\"URL\",\"");
  urlCmd += url;
  urlCmd += F("\"");
  if (!sendATCommand(urlCmd, F("OK"), 2000)) return;

  // 4. Start HTTP GET request
  Serial3.println(F("AT+HTTPACTION=0"));
  Serial.println(F("Sent: AT+HTTPACTION=0"));

  unsigned long startTime = millis();
  String response = "";

  // Wait for +HTTPACTION response
  while (millis() - startTime < 15000) {
    while (Serial3.available()) {
      char c = Serial3.read();
      response += c;
      if (response.indexOf(F("+HTTPACTION:")) != -1) {
        Serial.println(F("Received: "));
        Serial.println(response);
        goto proceed_to_read;
      }
    }
  }

  Serial.println(F("Timeout waiting for HTTPACTION"));
  return;

proceed_to_read:
  delay(100);  // slight delay to allow buffer fill

  // 5. Read the response data
  Serial3.println(F("AT+HTTPREAD"));
  Serial.println(F("Sent: AT+HTTPREAD"));
  delay(100);

  startTime = millis();
  response = "";

  while (millis() - startTime < 5000) {
    while (Serial3.available()) {
      char c = Serial3.read();
      response += c;
    }
  }

  Serial.println(F("HTTP Response:"));
  Serial.println(response);

  // 6. Terminate HTTP session
  sendATCommand(F("AT+HTTPTERM"), F("OK"), 2000);
}
