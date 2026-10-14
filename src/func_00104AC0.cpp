/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p0[0x10]; int f10, f14, f18, f1C; float f20, f24; char p1[0x10]; int f38; };
static inline int shift(int v, int flag) { return v >> (flag ? 1 : 0); }
extern "C" void func_00104AC0(Obj *o, int a1, int a2, int a3, int t0) {
    o->f10 = a1;
    o->f14 = shift(a2, o->f38);
    o->f18 = a3;
    o->f1C = shift(t0, o->f38);
}
