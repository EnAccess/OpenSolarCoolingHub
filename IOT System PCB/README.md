This directory contains all PCB design files for the IoT Monitoring System used in the Open Solar Cooling Hub. The design was created using Altium CircuitMaker.

# How to Open and Modify the PCB Design

# Download CircuitMaker
Visit the official download page:
https://circuitmaker.com/Download
Click “Download CircuitMaker” and follow the instructions for your operating system (Windows only).

# Install CircuitMaker
Run the downloaded .exe file.
Follow the installation wizard steps.
After installation, launch the software.

# Sign In or Register
You will need an Autodesk/Altium account to use CircuitMaker.
If you don’t have one, register during the first launch.
This is required since CircuitMaker uses cloud-based project management.

# Load the Project
Open CircuitMaker.
open this link: https://365.altium.com/files/FD40F198-177B-4D2F-B652-184317044322
Open Solar Cooling Hub PCB Project - Enaccess.PrjPcb
View and edit schematics using .SchDoc
Modify PCB layout using .CmpcbDoc
Generate new Gerber files for manufacturing
Adjust routing, component placement, and net labels
Re-export fabrication files via the .OutJob files



#  IoT System PCB – Folder Structure and Content Description

This folder contains all the files required for:
- PCB **fabrication**
- **Assembly** (PCBA)
- **Start 3D case modeling**
- Full **project source files** and **schematics**

The structure follows standard hardware development and manufacturing practices.

---

##  1. FAB – Fabrication Files

Located in:  
`FAB-Open Solar Cooling Hub PCB Project - Enaccess-A.1/`

These are the files required by PCB manufacturers to fabricate the **bare PCB** (without components).

###  Gerber Files

| Extension | Description                                |
|-----------|--------------------------------------------|
| `.GTL`    | Top copper layer                           |
| `.GBL`    | Bottom copper layer                        |
| `.GTO`    | Top silkscreen layer                       |
| `.GBO`    | Bottom silkscreen layer                    |
| `.GTS`    | Top soldermask                             |
| `.GBS`    | Bottom soldermask                          |
| `.GTP`    | Top paste layer                            |
| `.GBP`    | Bottom paste layer                         |
| `.GKO`    | Board outline / keep-out layer             |
| `.GM1`–`.GM16` | Mechanical layers, documentation     |
| `.REP`, `.RUL`, `.apr` | Reports and design rules     |
| `.APR_LIB` | Aperture macros used in CAM process       |

---

###  NC Drill Files

Located in: `NC Drill/`

| File           | Description                          |
|----------------|--------------------------------------|
| `.DRR`         | Drill report summary                 |
| `.TXT`         | Excellon drill file (for CNC)        |
| `.LDP`         | Layer pair definition                |

---

###  ODB++ Format

Located in: `ODB/`

This is a **comprehensive PCB manufacturing format** used by advanced fabrication services.

Contains:
- Layer definitions (copper, soldermask, silkscreen)
- Stackups and materials
- Drill and via data
- Netlists
- Profile and board outline

Use this folder if your manufacturer supports **ODB++** instead of Gerbers.

---

##  2. ExportSTEP – 3D Mechanical Model

| File                       | Purpose                          |
|----------------------------|----------------------------------|
| `IOT B oard FIle.step`     | 3D model of the PCB for enclosure design in CAD tools like OpenSCAD, Fusion 360 or SolidWorks |

---

##  3. PCBA – Assembly Files

Located in:  
`PCBA-Open Solar Cooling Hub PCB Project - Enaccess-[NO VARIATIONS]-A.1/`

These are used during **component assembly** (manual or SMT machine).

### 📋 Bill of Materials (BOM)

| File Name                                                    | Description                             |
|--------------------------------------------------------------|-----------------------------------------|
| `BOM_PartType-Open Solar Cooling Hub PCB Project.xlsx`       | List of all components, part numbers, footprints, and reference designators |

###  Pick & Place File

| File Name                             | Description                          |
|---------------------------------------|--------------------------------------|
| `Pick Place for IOT B oard FIle.txt`  | X/Y coordinates and orientation for all components |

###  Assembly Drawing

| File Name         | Description                         |
|-------------------|-------------------------------------|
| `Assembly.PDF`    | Visual layout of components for QC and hand assembly |

---

##  4. Schematic & Project Source Files

These files allow others to **modify, recompile, or regenerate** the PCB from source using **Circuitmaker PCB Designer** or **compatible EDA tools**.

| File Name                                     | Description                               |
|----------------------------------------------|-------------------------------------------|
| `IOT Schematic File.SchDoc`                  | Main schematic diagram                     |
| `IOT B oard FIle.CMPcbDoc`                   | PCB layout file                            |
| `Open Solar Cooling Hub PCB Project - Enaccess.PrjPcb` | Project file referencing schematic and PCB layout |
| `Open Solar Cooling Hub PCB Project - Enaccess.PrjPcbStructure` | Project structure definition         |
| `Assembly.OutJob`                            | Altium job file for exporting assembly files |
| `Fabrication.OutJob`                         | Altium job file for generating Gerbers, drills, etc. |
| `readme`                                     | Notes about the project (may be edited)    |

---

##  Summary of Folder Contents

| Folder / File                                | Purpose                                     |
|----------------------------------------------|---------------------------------------------|
| `Gerber/`                                     | PCB fabrication layers                      |
| `NC Drill/`                                   | Hole/via definitions                        |
| `ODB/`                                        | Consolidated PCB data                       |
| `ExportSTEP/`                                 | 3D mechanical model                         |
| `PCBA-.../BOM.xlsx`                           | Component sourcing                          |
| `PCBA-.../Pick Place.txt`                     | SMT assembly automation                     |
| `PCBA-.../Assembly.PDF`                       | Human-readable component placement          |
| `.SchDoc`, `.CMPcbDoc`, `.PrjPcb`, `.OutJob`  | Editable source files for schematic/layout  |

---

##  How to Use

###  To fabricate the board:
Send the contents of the **Gerber**, **NC Drill**, and optionally **ODB** folders to a PCB manufacturer like JLCPCB.

###  To assemble components:
Send the **BOM**, **Pick & Place**, and **Assembly PDF** to an SMT service provider like JLCPCB.

###  To modify or rebuild the design:
Open the schematic and PCB files using **Circuitmaker**, then use the **OutJob files** to regenerate outputs.

---

##  Licensing Note

All design files are licensed under the **CERN Open Hardware License v2.0**.  


