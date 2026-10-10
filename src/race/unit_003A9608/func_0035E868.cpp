typedef float f32;

struct Obj {
    char pad[8];
    f32 unk8;
    f32 unkC;
};

extern "C" void func_0035E868(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk8 = fparg0;
    arg0->unkC = fparg1;
}
