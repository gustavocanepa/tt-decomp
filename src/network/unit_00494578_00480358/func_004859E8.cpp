/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot {
    int m0;
    int m4;
    short *m8;
    char padC[4];
    short m10;
    char pad12[0x210 - 0x12];
    int m210;
    int m214;
    char pad218[0x418 - 0x218];
    int m418;
    char pad41C[0x41C - 0x41C];
};
struct O {
    char pad0[0x10];
    int m10;
    short *m14;
    char pad18[8];
    Slot slot[2];
};
extern "C" void *func_004831E8(void *, int) throw();
extern "C" void func_00483A10(O *) throw();

struct T {
    char c0;
    char pad1;
    short s2;
    short s4;
    short s6;
};

extern "C" void func_004859E8(O *o) {
    o->m10 = 0;
    short *p14 = o->m14;
    char *base = (char *)o + (1 - *(int *)((char *)o + 0x85C)) * 0x41C;
    *p14 = 0;
    Slot *s = (Slot *)(base + 0x24);
    T *t = (T *)(base + 0x23C);
    s->m4 = 0;
    *s->m8 = 0;
    s->m10 = 0;
    s->m210 = 0;
    s->m214 = 0;
    t->s4 = 0;
    t->s6 = 0;
    t->c0 = 1;
    s->m418 = 0;
    func_004831E8(o, 6);
    func_004831E8(o, 6);
    switch (s->m0) {
    case 1:
        return func_00483A10(o);
    case 2:
        func_00483A10(o);
        s->m0 = 1;
        break;
    case 0:
    default:
        break;
    }
}
