#include <Wire.h>
#include <Adafruit_MLX90614.h>

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

#define IR1 0x5A
#define IR2 0x5B
#define IR3 0x5C
#define IR4 0x5D
#define IR5 0x5E
#define IR6 0x6A
#define IR7 0x6B
#define IR8 0x6C
#define IR9 0x6D
#define IR10 0x6E

Adafruit_MLX90614 mlx;




void setup() {
  Serial.begin(9600);
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

  mlx.begin(); 

  pinMode(A0, OUTPUT);//Relay 1
  pinMode(A1, OUTPUT);//Relay 2
  pinMode(A2, OUTPUT);//Relay 3
  pinMode(A3, OUTPUT);//relay 4
  
}

void loop() {



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

  Serial.println("      New Updated Sensor Readings");
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


  //Serial.println(F(""));
  
  mlx.AddrSet(IR1); 
  Serial.print("IR1: ");
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  mlx.temp1 = mlx.readObjectTempC();
  delay(250);
  
  mlx.AddrSet(IR2); 
  Serial.print("IR2: ");
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  mlx.temp2 = mlx.readObjectTempC();
  delay(250);
  
  mlx.AddrSet(IR3); 
  Serial.print("IR3: ");
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  mlx.temp3 = mlx.readObjectTempC();
  delay(250);
  
  mlx.AddrSet(IR4); 
  Serial.print("IR4: ");
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  mlx.temp4 = mlx.readObjectTempC();
  delay(250);
  
  mlx.AddrSet(IR5); 
  Serial.print("IR5: ");
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  mlx.temp5 = mlx.readObjectTempC();
  delay(250);
  
  mlx.AddrSet(IR6); 
  Serial.print("IR6: ");
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  mlx.temp6 = mlx.readObjectTempC();
  delay(250);
  
  mlx.AddrSet(IR7); 
  Serial.print("IR7: ");
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  mlx.temp7 = mlx.readObjectTempC();
  delay(250);
  
  mlx.AddrSet(IR8); 
  Serial.print("IR8: ");
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  mlx.temp8 = mlx.readObjectTempC();
  delay(250);
  
  mlx.AddrSet(IR9); 
  Serial.print("IR9: ");
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  mlx.temp9 = mlx.readObjectTempC();
  delay(250);
  
  mlx.AddrSet(IR10); 
  Serial.print("IR10: ");
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  mlx.temp10 = mlx.readObjectTempC();
  delay(250);



  
  Serial.print("\n***********Average Temp:"); 
  float averageTemp = (mlx.temp1+mlx.temp2+mlx.temp3+mlx.temp4+mlx.temp5+mlx.temp6+mlx.temp7+mlx.temp8+mlx.temp9+mlx.temp10)/10;
  Serial.print(mlx.avgF=(mlx.temp1+mlx.temp2+mlx.temp3+mlx.temp4+mlx.temp5+mlx.temp6+mlx.temp7+mlx.temp8+mlx.temp9+mlx.temp10)/10); 
  Serial.print("***********\n");
  //Serial.println();

  //Minimum is 4 Degrees celcius and Maximum is 8 Degrees celcius
  if(averageTemp<=24){
    //4 degrees celcius
    Serial.println("Turn off Cooler");

    digitalWrite(A0, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(A1, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(A2, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(A3, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);                       // wait for a second
  //delay(1000);                       // wait for a second

    
    }else if(averageTemp>=30){
      //8 degrees celcius
      Serial.println("Turn On Cooler");
      digitalWrite(A0, HIGH);    // turn the LED off by making the voltage LOW
      digitalWrite(A1, HIGH);    // turn the LED off by making the voltage LOW
      digitalWrite(A2, HIGH);    // turn the LED off by making the voltage LOW
      digitalWrite(A3, HIGH);    // turn the LED off by making the voltage LOW
      
      }else{
        //Leave Else blank to let temperature make cycles between the maximum and minimum so that the relay doesnt do vibration switching on a boundary value
        Serial.println("Temperature is in Normal Range");
        digitalWrite(A0, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(A1, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(A2, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(A3, LOW);    // turn the LED off by making the voltage LOW
        }

        Serial.println("Send All Sensor Data to Remote Database");
        Serial.println();
        //Serial.println();
        delay(7000);
}
