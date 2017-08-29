/*
 * Various modules to create a maintanence panel.
 */

module cabinet(width = 50, height = 30, depth = 20, border = 5) {
    difference() {
        cube([width, height, depth]);
        translate([border, border, border]) cube([width - 2*border, height - 2*border, depth]);
    };
}

module cover(width = 50, height = 30, depth = 5) {
    cube([width, height, depth]);
}

translate([0, 0, 0]) cabinet();
translate([0, 0, 60]) cover();