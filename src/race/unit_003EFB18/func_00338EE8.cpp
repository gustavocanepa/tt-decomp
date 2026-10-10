typedef int s32;

struct Tmp { s32 pad[4]; s32 m10; s32 pad2[3]; };
struct Self { s32 m0; };
extern char D_005F3770[];
extern "C" void func_0047DB20(Tmp *, char *, s32);
extern "C" void func_0041F840(s32);

extern "C" void func_00338EE8(Self *self) {
    Tmp t;
    func_0047DB20(&t, D_005F3770, 1);
    self->m0 = t.m10;
    func_0041F840(t.m10);
}
