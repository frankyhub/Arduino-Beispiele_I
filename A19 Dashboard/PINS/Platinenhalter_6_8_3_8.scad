$fn=130;

zylD=6.6;   //Zylinder-Durchmesser
zylH=8;    //Zylinder-Höhe
pinD=3;     //PIN-Durchmesser
pintack(h=8);//Pin-Höhe


module pin(h=10, r=4, lh=3, lt=1) { 
    pin_vertical(h, r, lh, lt);
}

module pintack(h=10, r=pinD, lh=3, lt=1,) {
   union() {
    cylinder(h=zylH, r=zylD);
    translate([0, 0, zylH]) pin(h, r, lh, lt);
  }
}

module pin_vertical(h=10, r=4, lh=3, lt=1) {

  difference() {
    pin_solid(h, r, lh, lt);
    translate([-r*0.5/2, -(r*2+lt*2)/2, h/4]) cube([r*0.5, r*2+lt*2, h]);
    translate([0, 0, h/4]) cylinder(h=h+lh, r=r/2.5, $fn=20);
    translate([-r*2, -lt-r*1.125, -1]) cube([r*4, lt*2, h+2]);
    translate([-r*2, -lt+r*1.125, -1]) cube([r*4, lt*2, h+2]);
  }
}

module pin_solid(h=10, r=4, lh=3, lt=1) {
  union() {

    cylinder(h=h-lh, r=r, $fn=30);
    translate([0, 0, h-lh]) cylinder(h=lh*0.25, r1=r, r2=r+(lt/2), $fn=30);
    translate([0, 0, h-lh+lh*0.25]) cylinder(h=lh*0.25, r=r+(lt/2), $fn=30);    
    translate([0, 0, h-lh+lh*0.50]) cylinder(h=lh*0.50, r1=r+(lt/2), r2=r-(lt/2), $fn=30);    
  }
}
