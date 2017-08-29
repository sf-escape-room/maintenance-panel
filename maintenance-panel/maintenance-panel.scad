/*
 * Various modules to create a maintanence panel.
 */

module cabinet(width=50, height=30, depth=20, border=3, rim_border=5, rim_depth=3) {
    difference() {
        union() {
            translate([-rim_border, -rim_border, depth - rim_depth]) cube([width + 2*rim_border, height + 2*rim_border, rim_depth]);
            cube([width, height, depth]);
        }
        translate([border, border, border]) cube([width - 2*border, height - 2*border, depth]);
    };
}

module cover(width = 60, height = 40, depth = 3) {
    cube([width, height, depth]);
}

module assembly(width=50, height=30, depth=20, border=3, rim_border=5, rim_depth=3) {
    translate([0, 0, 0]) cabinet(width=width, height=height, depth=depth, border=border, rim_border=rim_border, rim_depth=rim_depth);
    translate([-rim_border, -rim_border, 2*height]) cover(width=width + 2*rim_border, height=height + 2*rim_border, depth=border);
}

assembly();