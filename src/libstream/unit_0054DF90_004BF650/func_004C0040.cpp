/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Lock;
extern "C" void func_004A4D68(Lock *l);
extern "C" void func_004A4DD8(Lock *l);

struct Pad {
    unsigned char b0, b1, b2, b3;
};

struct Obj {
    char pad0[0x10];
    char lock[0x70];
    int state;
    unsigned char mode;
    char pad85[0xF];
    int kind;
    unsigned char value[2];
};

extern "C" void func_004C0040(Obj *o, Pad *p) {
    func_004A4D68((Lock *)o->lock);
    unsigned int v = (p->b2 & 1) | (p->b3 << 1);
    o->mode = 3;
    o->value[1] = v >> 8;
    o->kind = 2;
    o->value[0] = v;
    o->state = 1;
    func_004A4DD8((Lock *)o->lock);
}
