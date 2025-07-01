<div align="center">

# OpenSolarCoolingHub Documentation Index

**Solar Powered IoT Cooling Hubs**  
_This is a project that brings together architecture, electronics, Internet of Things (IoT), and solar engineering to create affordable and sustainable cooling systems specifically designed for off-grid communities. By integrating smart design with energy-efficient technology and renewable energy sources, the project aims to provide reliable cooling solutions where access to electricity is limited or unavailable. The goal is to improve quality of life, reduce post-harvest losses, and support health and food storage needs in remote or underserved areas._

## 🔗 Cold Room Exterior
This image shows the exterior design of the solar-powered cold room, constructed with durable, insulated materials to maintain optimal internal temperatures. The structure is optimized for energy efficiency and environmental resilience, making it ideal for use in rural or off-grid locations. Its compact and modular design allows for easy transport, installation, and maintenance in remote areas.

![Cold Room Exterior](/Project%20Images%20and%20Videos/opensolarimage.PNG)


## 🔗 IOT Sytem PCB
Displayed here is the custom-designed Printed Circuit Board (PCB) for the IoT system. This board forms the core of the system’s electronics, managing sensor data, control signals, and wireless communication. The PCB is engineered to interface with temperature, humidity, and door sensors, and is optimized for low power consumption and real-time data transmission, supporting remote monitoring and control via a web dashboard.

![IOT Sytem PCB](/Project%20Images%20and%20Videos/PCB%203D%20ANGLE.PNG)

---

## 🔗 Live IoT Dashboard  
The live IoT dashboard provides real-time monitoring of environmental conditions inside the cold room. It displays key metrics such as temperature, humidity, and system status, allowing users to remotely track and manage performance. The intuitive interface makes it easy for operators to respond to alerts and optimize energy use, ensuring food and medical supplies remain safely stored.

👉 [View Real-time Sensor Display](http://solarcoolingproject.atwebpages.com/RealtimeDisplayImproved.php)

![Dashboard Screenshot](/Project%20Images%20and%20Videos/solarimagedashboard.PNG)

---

<br><br><br><br>

## 📂 Folder-wise Documentation Overview
<br>

## 🧊 1. Cold Room Design 
A comprehensive architectural and systems layout for the off-grid cold room solution. Designed using SolidWorks and Archicad, this section includes construction drawings, 3D models, conceptual diagrams, and thermal/digital integration details.

🔗 Archicad Files - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/Cold%20Room%20Design/ColdRoom/Archicad%20Files) : Contains the primary architectural plan (FarmFreeze_Munakyalo (ArchiCAD 25).pln) with accompanying documentation.

🔗 CAD Exports - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/Cold%20Room%20Design/ColdRoom/CAD%20Exports) : Includes PDFs and images of the VIP latrine, tank and base, gate, fence, and full site layout.

🔗 Diagrams - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/Cold%20Room%20Design/ColdRoom/Diagrams) : Contains structural and conceptual system diagrams.

🔗 System Architecture - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/Cold%20Room%20Design/SystemArchitecture) : Describes the thermal, electrical, and digital system integration to support off-grid functionality.<br><br>


## 📎 2. Component Datasheets
This folder contains the technical specifications of all key components used across the system. Includes datasheets for sensors (DHT22, MLX90614), power modules, GSM, and Arduino boards. - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/Component%20Datasheets) 

🔗 readme - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/edee4dc87492873370343514b17ce90f6df560b8/Component%20Datasheets) : Lists and explains each hardware module with links to PDFs.<br><br>


## 💰 3. Financial Model Templates
An Excel-based financial modeling toolkit for evaluating the Pay-as-You-Store pricing strategy and sustainability metrics.
 - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/Financial%20Model%20Templates) 
🔗 readme.md - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/blob/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/Financial%20Model%20Templates/readme.md) : Overview of model usage.

📊 Includes:

Pay_as_You_Store_Financial_Model.xlsx - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/blob/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/Financial%20Model%20Templates/Pay_as_You_Store_Financial_Model.xlsx) 

User_Guide_Pay_as_You_Store_Model.pdf - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/blob/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/Financial%20Model%20Templates/User_Guide_Pay_as_You_Store_Model.pdf) <br><br>


## 🧠 4. IoT Firmware
Embedded C/C++ code written and compiled using Arduino IDE, designed for the Arduino Mega. This firmware handles sensor input, GSM communication, and relay control logic.

🔗 libraries - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/IOT%20System%20Arduino%20Firmware/libraries) : Required libraries like DHTlib and Adafruit MLX90614.

🔗 src - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/IOT%20System%20Arduino%20Firmware/src) : Source code examples including merged sensor tests, GSM modules, relay switching, and address configuration.

🔗 README.md - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/blob/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/IOT%20System%20Arduino%20Firmware/src/readme) : Firmware overview and setup guide.<br><br>


## 🧱 5. IoT System Enclosure
Designed in OpenSCAD, this section provides both editable 3D models and printable STL files for creating protective enclosures for the PCB.

🔗 3D Models - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/IOT%20System%20Enclosure/3D%20Models) : .step files for customization and mechanical fitting.

🔗 STL Files - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/IOT%20System%20Enclosure/STL%20Files) : Ready-to-print STL files for 3D printing.<br><br>


## 💻 6. IoT PCB Design
PCB schematics, layout, and manufacturing-ready files created using CircuitMaker (Altium's free tool). Includes Gerbers, BoMs, pick-and-place files, and fabrication data. - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/IOT%20System%20PCB) 

🔗 Export Files - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/IOT%20System%20PCB/Export%20FIles) : Contains all files for fabrication, drilling, and assembly.

🔗 schematics - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/b22f68ab80e7eb956e8c33c35e9078b9c4da2ed1/IOT%20System%20PCB/schematics) : Design files including SchDoc, CMPcbDoc, and the project structure.<br><br>


## 🧪 7. IoT Simulation
Logic simulation and virtual validation of the IoT system using Proteus Professional. - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/2582ba2290185b933453911665ca5a5f1b0d1c63/IOT%20System%20Simulation%20with%20Proteus%20Pro) 

🔗 readmefile.md - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/blob/2582ba2290185b933453911665ca5a5f1b0d1c63/IOT%20System%20Simulation%20with%20Proteus%20Pro/readmefile.md) : Instructions and configuration.

Includes:

Cold Solar Storage Proteus Simulation.pdsprj<br><br>


## 🌐 8. IoT System Website
Built with PHP, MySQL, HTML, CSS, the cloud dashboard enables real-time monitoring of cold room conditions remotely.

🔗 public - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/2582ba2290185b933453911665ca5a5f1b0d1c63/IOT%20System%20Website/public) : All PHP scripts for inserting, fetching, and displaying sensor data.<br><br>
🔗 readmefile.md - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/blob/2582ba2290185b933453911665ca5a5f1b0d1c63/IOT%20System%20Website/README.md)



## 🎥 9. Project Images and Videos
A visual gallery showing the project progress and deliverables including 3D PCB renderings and schematics.
 - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/2582ba2290185b933453911665ca5a5f1b0d1c63/Project%20Images%20and%20Videos) 


Includes: PCB 2D.PNG, PCB 3D ANGLE.PNG, Schematic.PNG, etc.<br><br>


## 🧪 10. System Testing
This section documents the calibration, test planning, and final performance results of the overall system.

🔗 Calibration - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/2582ba2290185b933453911665ca5a5f1b0d1c63/System%20Testing/Calibration) : Logs and notes on sensor tuning.

🔗 TestPlans - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/2582ba2290185b933453911665ca5a5f1b0d1c63/System%20Testing/TestPlans) : Structured validation plans.

🔗 TestResults - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/2582ba2290185b933453911665ca5a5f1b0d1c63/System%20Testing/TestResults) : Performance outcomes and notes.<br><br>


## 📚 11. Technical References
Academic and industry references used for component selection, system design, and technical justification.
 - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/2582ba2290185b933453911665ca5a5f1b0d1c63/Technical%20References) 
<br><br>


## 📘 12. User Manual
End-user guide for setup, usage, and maintenance of the cold room system.
 - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/tree/2582ba2290185b933453911665ca5a5f1b0d1c63/User%20Manual) 
🔗 readme.md - [Link](https://github.com/EnAccess/OpenSolarCoolingHub/blob/2582ba2290185b933453911665ca5a5f1b0d1c63/User%20Manual/readme.md) : Step-by-step instructions for installation and safe use. <br><br>

---

</div>
