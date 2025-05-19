#include <Wire.h>
#include <Adafruit_MLX90614.h>
#define IR1 0x5A
#define IR2 0x5B
//#define IR3 0x5B
Adafruit_MLX90614 mlx;

void setup() {
  Serial.begin(9600);
  

  Serial.println("Adafruit MLX90614 test");  

  mlx.begin(); 
  
  
}

void loop() {
  
  mlx.AddrSet(IR1); 
  Serial.print("IR1: ");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  mlx.temp1 = mlx.readObjectTempC();
  delay(250);
  mlx.AddrSet(IR2); 
  Serial.print("IR2: ");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  mlx.temp2 = mlx.readObjectTempC();
  delay(250);
//  mlx.AddrSet(IR3); 
//  Serial.print("IR3: ");
//  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
//  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
//  mlx.temp3 = mlx.readObjectTempF();
//  delay(250);
  Serial.print("\n***********Average Temp:"); Serial.print(mlx.avgF=(mlx.temp1+mlx.temp2)/2); 
  Serial.print("***********\n");
  Serial.println();
  delay(1000);
}
