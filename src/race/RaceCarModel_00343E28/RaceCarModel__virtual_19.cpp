/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct O0 { char b[0x40]; };
struct O40 { s32 f0, f4, f8; char pad[0x14]; };
struct A { s32 f0, f4; char pad[0x18]; };
struct B { void *f0; s32 f4; char pad[8]; };
struct Obj { char pad[0x18]; char sub[1]; };
extern "C" void func_00343250(void);
extern "C" void func_0042F140(O0 *, A *, B *, s32);
extern "C" s32 func_0041A630(void *, s32);
extern "C" s32 func_0041A650(void *);
extern "C" void func_0041B060(void *);
extern "C" void func_0041B070(void *);
extern "C" void func_0041DB78(const char *, O0 *, s32);
extern "C" void func_0047DFB0(O40 *, O0 *);
extern "C" s32 func_004E5700(const char *, s32, s32);
extern "C" void RaceCarModel__virtual_19(Obj *self, const char *name, s32 arg2) {
    if (name == 0) {
        func_0041B070(self->sub);
        return;
    }
    if (*name == 0) {
        func_0041B060(self->sub);
        return;
    }
    void *s2 = self->sub;
    if (func_004E5700(name, func_0041A650(s2), 8) != 0) {
        O0 o0;
        O40 o40;
        A a;
        B b;
        func_0041DB78(name, &o0, arg2);
        func_0047DFB0(&o40, &o0);
        s32 v = func_0041A630(s2, (o40.f8 + 0x3F) & ~0x3F);
        A *pa = &a;
        B *pb = &b;
        pa->f0 = v;
        pa->f4 = 0;
        pb->f0 = (void *)func_00343250;
        pb->f4 = (s32)self;
        func_0042F140(&o0, pa, pb, 1);
    }
}
