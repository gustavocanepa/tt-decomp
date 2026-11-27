/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { char p0[0x28]; float a; char p1[0xC0 - 0x2C]; float x; float y; char p2[0xF4 - 0xC8]; };
struct Info { char p0[1]; unsigned char n; };
struct Obj { char p0[0x10]; void *k; char p1[0x164 - 0x14]; Ent e[1]; };
extern "C" Info *func_002FD378(void *) throw();
extern "C" float func_004B2B08(float);
static inline void update(Ent *e, float m1) {
    float x = e->x;
    float f = e->a * 0x1.999998p-4f;
    float y = e->y;
    if (f < 0.0f) f = -f;
    if (f > 2.0f) f = 2.0f;
    f = f + m1;
    y = y + ((((2.0f * ((f - m1) * func_004B2B08(1.0f)) + m1) - x) * 500.0f - y * 10.0f) * 0x1.111110p-6f);
    x = x + y * 0x1.111110p-6f;
    if (x > 1.0f) { x = 1.0f; y = 0.0f; }
    else if (x < m1) { x = m1; y = 0.0f; }
    e->x = x;
    e->y = y;
}
extern "C" void func_002FFB48(Obj *o) {
    int i = 0;
    Info *inf = func_002FD378(o->k);
    for (; i < inf->n; i++) update(&o->e[i], -1.0f);
}
