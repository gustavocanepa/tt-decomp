typedef int s32;
typedef unsigned int u32;
struct S { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C; };
extern "C" void func_0045D2B0(void *);
extern "C" s32 malloc(s32);
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" s32 func_0045D308(S *self, s32 arg1) {
    s32 p1c, p18, p14, p10, base, c, b, a;
    func_0045D2B0(self);
    b = (arg1 + 3) & ~3;
    a = (arg1 + 4) & ~3;
    c = b * 2;
    base = malloc(a + (b + c) + 0x20000);
    p10 = base + a;
    p14 = p10 + c;
    p18 = p14 + b;
    p1c = p18 + 0x10000;
    self->f8 = base;
    if (base != 0) {
        self->fC = base;
        self->f1C = p1c;
        self->f10 = p10;
        self->f14 = p14;
        self->f18 = p18;
        func_004F6678((void *)base, 0, a + c + b);
        self->f4 = arg1;
        self->f0 = 1;
        return 1;
    }
    return base;
}
