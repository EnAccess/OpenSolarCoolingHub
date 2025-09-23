# 🛠️ FarmFreeze System – PCB Assembly Guide

This document provides step-by-step instructions for assembling and soldering the FarmFreeze System PCB, including positioning of sensors and modules.

---

## 1. Preparation
- Work on a **clean, static-free surface**.  
- Required tools:
  - Soldering iron
  - Solder wire (60/40 or lead-free)
  - Flux
  - Side cutters
  - Multimeter  
- Verify all **components and sensors** against the Bill of Materials (BOM).

---

## 2. PCB Orientation
When viewing the PCB:
- The **project details** (ClimaVault Africa Limited, Enaccess Foundation, FarmFreeze System) are printed on the top and bottom edges.  
- Pin headers are placed along the **left and right sides**.  
- Sensor pads are labeled:
  - `CURRENT SENSOR`
  - `VOLTAGE SENSOR`
  - `TEMP`
  - `HUMIDITY`

---

## 3. Assembly Steps

### Step 1: Arduino Mega Headers
- Insert and solder the **female headers** in the central rectangular area.
- These headers hold the **Arduino Mega 2560**.  
- Keep them **straight and vertical** for smooth plugging/unplugging.

### Step 2: Sensor Modules
- **DHT22 (Humidity Sensors)**  
  - Solder in the `HUMIDITY` slots.  
  - Ensure the white vented casing is **facing outward** for airflow.  

- **GY-906 MLX90614 (Infrared Temp Sensors)**  
  - Solder in the `TEMP` slots.  
  - The metal sensing head should face outward toward the cooling chamber contents.  

- **ZMPT101B (Voltage Sensor)**  
  - Solder in the `VOLTAGESENSOR` area.  
  - Keep AC input terminals facing the edge of the PCB for safe wiring.  

- **ACS712 (30A Current Sensor)**  
  - Solder in the `CURRENTSENSOR` slot.  
  - Screw terminals should face outward for connecting solar/battery lines.  

### Step 3: GSM Module
- Insert the **SIM800 GSM/GPRS Module** into its header pins (`SIM` section).  
- Orient it so that the **antenna side faces outward** for better signal reception.

---

## 4. Sensor Positioning Guidelines
- **DHT22**: Place in free airflow, away from heat sources to avoid false readings.  
- **MLX90614**: Aim it toward stored goods not the walls.  
- **ACS712**: Ensure thick wires are used for current connections. Tighten screws securely.  
- **ZMPT101B**: Keep AC wiring separate from low-voltage circuits for safety.

---

## 5. Final Checks
- After soldering, use a multimeter to:
  - Check **continuity** of all connections.  
  - Verify no shorts exist between **VCC and GND**.  
- Test each sensor **individually with Arduino Mega** before running the full system.  

---

✅ Following this guide will ensure proper assembly, accurate sensor placement, and safe operation of the FarmFreeze System.


