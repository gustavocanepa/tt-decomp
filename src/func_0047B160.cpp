/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Obj { int f0,f4,f8; unsigned long f10; int f18,f1c; unsigned char f20; Obj(int, const unsigned char *) __asm__("func_0047B160"); };
static inline u32 read32(const unsigned char *p) { return p[0] | (p[1]<<8) | (p[2]<<16) | (p[3]<<24); }
Obj::Obj(int n, const unsigned char *p) {
    Obj *o = this;
    o->f0 = n;
    int type = p[0];
    switch (type) {
    case 0:
        o->f4 = read32(p + 1);
        o->f8 = -1;
        o->f18 = 0;
        o->f1c = 0;
        o->f20 = 1;
        return;
    case 1:
        o->f4 = -1;
        o->f8 = read32(p + 1);
        o->f10 = read32(p + 5);
        o->f18 = o->f1c = read32(p + 9);
        o->f20 = 0;
        return;
    case 2:
        o->f4 = -1;
        o->f8 = read32(p + 1);
        o->f10 = read32(p + 5);
        o->f18 = read32(p + 9);
        o->f1c = read32(p + 13);
        o->f20 = type;
        return;
    }
}
