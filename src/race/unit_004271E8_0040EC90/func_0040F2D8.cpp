/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[0xA8]; unsigned f; };
struct Row { int v; char pad[0x1C]; };
extern char D_00585A30[];
extern "C" int func_0040B940(void *, int, int, void *);

static inline bool getRow(unsigned long k, Row *r) {
    return func_0040B940(D_00585A30, (int)k, 0x22, r) != 0;
}

extern "C" int func_0040F2D8(Obj *o) {
    Row r;
    unsigned long k = o->f;
    if (getRow(k, &r)) return r.v;
    return -1;
}
