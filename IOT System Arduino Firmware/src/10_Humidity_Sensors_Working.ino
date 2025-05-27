#include "DHT.h"

#define DHTPIN1 4
#define DHTPIN2 5
#define DHTPIN3 6
#define DHTPIN4 7
#define DHTPIN5 8
#define DHTPIN6 9
#define DHTPIN7 10
#define DHTPIN8 11
#define DHTPIN9 12
#define DHTPIN10 13

#define DHTTYPE DHT22   

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
DHT dht4(DHTPIN4, DHTTYPE);
DHT dht5(DHTPIN5, DHTTYPE);
DHT dht6(DHTPIN6, DHTTYPE);
DHT dht7(DHTPIN7, DHTTYPE);
DHT dht8(DHTPIN8, DHTTYPE);
DHT dht9(DHTPIN9, DHTTYPE);
DHT dht10(DHTPIN10, DHTTYPE);


void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();
  dht5.begin();
  dht6.begin();
  dht7.begin();
  dht8.begin();
  dht9.begin();
  dht10.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  float h1 = dht1.readHumidity(); float t1 = dht1.readTemperature();
  float h2 = dht2.readHumidity(); float t2 = dht2.readTemperature();
  float h3 = dht3.readHumidity(); float t3 = dht3.readTemperature();
  float h4 = dht4.readHumidity(); float t4 = dht4.readTemperature();
  float h5 = dht5.readHumidity(); float t5 = dht5.readTemperature();
  float h6 = dht6.readHumidity(); float t6 = dht6.readTemperature();
  float h7 = dht7.readHumidity(); float t7 = dht7.readTemperature();
  float h8 = dht8.readHumidity(); float t8 = dht8.readTemperature();
  float h9 = dht9.readHumidity(); float t9 = dht9.readTemperature();
  float h10 = dht10.readHumidity(); float t10 = dht10.readTemperature();

  delay(100);
  



  Serial.print(F("Humidity1: ")); Serial.print(h1); Serial.print(F("%  Temperature1: ")); Serial.print(t1);  Serial.println(F("°C "));
  Serial.print(F("Humidity2: ")); Serial.print(h2); Serial.print(F("%  Temperature2: ")); Serial.print(t2);  Serial.println(F("°C "));
  Serial.print(F("Humidity3: ")); Serial.print(h3); Serial.print(F("%  Temperature3: ")); Serial.print(t3);  Serial.println(F("°C "));
  Serial.print(F("Humidity4: ")); Serial.print(h4); Serial.print(F("%  Temperature4: ")); Serial.print(t4);  Serial.println(F("°C "));
  Serial.print(F("Humidity5: ")); Serial.print(h5); Serial.print(F("%  Temperature5: ")); Serial.print(t5);  Serial.println(F("°C "));
  Serial.print(F("Humidity6: ")); Serial.print(h6); Serial.print(F("%  Temperature6: ")); Serial.print(t6);  Serial.println(F("°C "));
  Serial.print(F("Humidity7: ")); Serial.print(h7); Serial.print(F("%  Temperature7: ")); Serial.print(t7);  Serial.println(F("°C "));
  Serial.print(F("Humidity8: ")); Serial.print(h8); Serial.print(F("%  Temperature8: ")); Serial.print(t8);  Serial.println(F("°C "));
  Serial.print(F("Humidity9: ")); Serial.print(h9); Serial.print(F("%  Temperature9: ")); Serial.print(t9);  Serial.println(F("°C "));
  Serial.print(F("Humidity10: ")); Serial.print(h10); Serial.print(F("%  Temperature10: ")); Serial.print(t10);  Serial.println(F("°C "));


  Serial.println(F(""));
  
  
}
