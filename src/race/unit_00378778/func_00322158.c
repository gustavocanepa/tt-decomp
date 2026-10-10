struct A { char pad[0x1c]; float f; };
struct B { char pad[0x44]; float g; };
float func_00322158(struct A *a, struct B *b) { float x = a->f; return b->g * x; }
