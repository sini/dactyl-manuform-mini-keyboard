lein generate
openscad -o things/plate.dxf things/plate.scad >/dev/null 2>&1 &
openscad -o things/right.stl things/right.scad >/dev/null 2>&1 &
openscad -o things/left.stl  things/left.scad >/dev/null 2>&1 &

wait