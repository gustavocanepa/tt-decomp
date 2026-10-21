struct Inner { char p0[0x58]; float f54; };
struct Obj { char p0[0x10]; Inner *f10; char p14[0x104 - 0x14]; };
struct Sub { char p0[0x488]; float f468; };
extern "C" void func_002E5058(void);
extern "C" int func_002EFBD0(void *self);

extern "C" int func_002F0198(Obj *self, float fparg0) {
    float f20 = fparg0 * 0.017453292f;
    float f0 = self->f10->f54;
    float f1 = -f0;
    Sub *s = (Sub *)((char *)self + 0x104);
    if (f20 < f1) {
        f20 = f1;
    } else if (f0 < f20) {
        f20 = f0;
    }
    func_002E5058();
    s->f468 = f20;
    return func_002EFBD0(self);
}
