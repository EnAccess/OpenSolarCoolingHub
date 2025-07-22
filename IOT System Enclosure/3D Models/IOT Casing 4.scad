// --- Parameters ---
board_size = [174.88, 153.67, 13.84]; // Measured from STL
margin = 5;
wall = 3;
base_height = 5;
cover_thickness = 3;
hole_width = 10;
hole_height = 4;
hole_spacing = 5;
radius = 6;
screw_hole_dia = 3;
post_dia = 6;         // Diameter of screw post
vent_hole_dia = 4;

// --- Animation explosion factor ---
explode_factor = $t; // use $t for animation (range 0 to 1)

// --- Exploded distances ---
explode_cover = 60 * explode_factor;
explode_board = 35 * explode_factor;

// --- Derived dimensions ---
case_x = board_size[0] + 2 * margin;
case_y = board_size[1] + 2 * margin;
case_z = board_size[2] + base_height + wall;
stl_offset = [-22.61, -11.68, 3.5];

// --- Screw post module ---
module screw_post(x, y) {
    translate([x, y, base_height])
        cylinder(h = case_z - cover_thickness - base_height, r = post_dia / 2, $fn=30);
}

// --- Main casing with screw posts ---
module casing_body() {
    color("lightgray")
    difference() {
        minkowski() {
            cube([case_x - 2*radius, case_y - 2*radius, case_z - cover_thickness], center=false);
            translate([radius, radius, 0])
                cylinder(h=0.5, r=radius, $fn=50);
        }

        translate([margin, margin, base_height + 2])
            cube(board_size);

        for (i = [0:4]) {
            translate([-0.01, margin + i * (hole_width + hole_spacing), base_height + 3])
                cube([wall + 0.02, hole_width, hole_height]);
        }

        for (i = [0:1]) {
            translate([margin + i * (hole_width + hole_spacing), -0.01, base_height + 3])
                cube([hole_width, wall + 0.02, hole_height]);
        }

        translate([(case_x - hole_width) / 2, case_y - wall - 0.01, base_height + 3])
            cube([hole_width, wall + 0.02, hole_height]);

        for (x = [5, case_x - 5])
            for (y = [5, case_y - 5])
                translate([x, y, case_z - cover_thickness])
                    cylinder(h = 10, r = screw_hole_dia / 2, $fn=30);
    }

    // Screw posts (4 corners)
    color("silver")
    for (x = [5, case_x - 5])
        for (y = [5, case_y - 5])
            screw_post(x, y);
}

// --- Top Cover ---
module top_cover() {
    color("blue")
    difference() {
        translate([0, 0, case_z - cover_thickness])
            minkowski() {
                cube([case_x - 2*radius, case_y - 2*radius, cover_thickness], center=false);
                translate([radius, radius, 0])
                    cylinder(h=0.5, r=radius, $fn=50);
            }

        for (x = [5, case_x - 5])
            for (y = [5, case_y - 5])
                translate([x, y, case_z - cover_thickness - 1])
                    cylinder(h = 10, r = screw_hole_dia / 2, $fn = 30);
    }
}

// --- Labels + Vent Holes ---
module label_and_vents() {
    color("green") {
        translate([10, case_y/2 + 30, case_z - 2])
            linear_extrude(height = 3.5)
                text("      SOLAR COOLING HUB", size = 8, font = "Arial", halign="left");

        translate([10, case_y/2 + 10, case_z - 2])
            linear_extrude(height = 3.5)
                text(" BY MUNAKYALO AGROFRESH", size = 8, font = "Arial", halign="left");

        translate([10, case_y/2 - 10, case_z - 2])
            linear_extrude(height = 3.5)
                text("                ENACCESS", size = 8, font = "Arial", halign="left");
    }

    // Vent holes
    color("black")
    for (x = [case_x/2 - 15, case_x/2 - 5, case_x/2 + 5, case_x/2 + 15])
        for (y = [15, 25, 35])
            translate([x, y, case_z - 2])
                cylinder(h = 2, r = vent_hole_dia / 2, $fn=30);
}

// --- Assembly with Animation ---
casing_body();

translate([0, 0, explode_cover])
    top_cover();

translate([0, 0, explode_cover])
    label_and_vents();

color("red")
translate([margin, margin, base_height + explode_board])
    translate(stl_offset)
        import("IOT B oard FIle.stl");
