# Download & Install OpenSCAD
Visit the official OpenSCAD site:
 https://openscad.org/downloads.html
Download the version for your OS (Windows, Linux, or Mac).
Install it using default options.

# Open and Preview Your Casing Model
Launch OpenSCAD.
Click File > Open and choose one of your .scad files (start with IOT Casing.scad or IOT Casing 4.scad).
Press F5 or click the Preview button (eyeball icon) to load the 3D model.

# Modify the Design
You can edit parameters at the top of the .scad file. For example:
casing_length = 120;
casing_width = 80;
casing_height = 40;
wall_thickness = 3;
Modify dimensions, positions of holes, slots, screw posts, or text labels depending on your needs.
Re-preview with F5 or render with F6.

# Export STL for 3D Printing
Press F6 to do a full render of the model.
Then go to File > Export > Export as STL.
Name it something like IOT_Casing_Final.stl.
You can now open it in a slicer like Cura or PrusaSlicer and 3D print.
