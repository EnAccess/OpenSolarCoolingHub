/*************************************************** 
  This is a library example for the MLX90614 Temp Sensor

  Designed specifically to work with the MLX90614 sensors in the
  adafruit shop
  ----> https://www.adafruit.com/products/1748
  ----> https://www.adafruit.com/products/1749

  These sensors use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_MLX90614.h>

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
  

  Serial.println("Adafruit MLX90614 test");  

  mlx.begin(); 
  
  
}

void loop() {
  
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
  Serial.print(mlx.avgF=(mlx.temp1+mlx.temp2+mlx.temp3+mlx.temp4+mlx.temp5+mlx.temp6+mlx.temp7+mlx.temp8+mlx.temp9+mlx.temp10)/10); 
  Serial.print("***********\n");
  Serial.println();
  delay(1000);
}
