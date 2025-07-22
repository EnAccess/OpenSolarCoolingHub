This folder contains the working Arduino sketch used to control and collect data from the sensors for the OpenSolarCoolingHub IoT system.
Main code file:
src/Sensors_and_Remote_Merged_Working_Fine_UNO/Sensors_and_Remote_Merged_Working_Fine_UNO.ino


# How to Set Up the Arduino Environment
Step 1: Install Arduino IDE v1.8
Download Arduino IDE 1.8 from the official site:
https://www.arduino.cc/en/software
Scroll down to “Previous Releases” and select Arduino 1.8.19 (or any v1.8.x).
Choose your OS (Windows/Mac/Linux) and install the IDE.

# Install Required Libraries
Once Arduino IDE is installed:
Launch the IDE
Go to Sketch → Include Library → Manage Libraries
Search and install the following libraries:
DHT sensor library by Adafruit
Adafruit Unified Sensor
LiquidCrystal_I2C (for I2C LCD)
OneWire
DallasTemperature (for DS18B20 temperature sensor)
Any other libraries specific to the sensor modules you're using
You can also manually add libraries by copying them into the libraries folder located at: Documents/Arduino/libraries/


# Open and Modify the Firmware
From the IDE, go to File → Open, then navigate to:
src/Sensors_and_Remote_Merged_Working_Fine_UNO/Sensors_and_Remote_Merged_Working_Fine_UNO.ino
Make your changes in the .ino file. For example:
Update sensor thresholds
Add new sensors
Change pin definitions to match your hardware setup


# Upload to Arduino Board
Connect your Arduino Mega to the computer via USB.
In the IDE:
Go to Tools → Board → Arduino Mega
Go to Tools → Port → Select the correct COM port
Click the Upload button (right arrow icon) to compile and upload the code.
Once uploaded:
The system reads sensors like temperature, humidity, etc.
The display shows real-time values.
The SIM module sends alerts based on conditions.
