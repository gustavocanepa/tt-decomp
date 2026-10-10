typedef int s32;
typedef float f32;

extern s32 D_00794E70;

extern "C" void func_00346CF0(f32 fparg0, f32 fparg1);

extern "C" void func_00346D30(f32 fparg0) {
    D_00794E70 = 0;
    func_00346CF0(1.0f, fparg0);
}
