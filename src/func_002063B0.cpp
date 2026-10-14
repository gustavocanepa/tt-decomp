typedef int s32;
typedef float f32;

extern "C" void func_002065C0(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3, s32 arg4);

extern "C" void func_002063B0(s32 arg0, f32 fparg0, f32 fparg1) {
    f32 sp0 = fparg0;
    f32 sp4 = fparg1;
    func_002065C0(arg0, &sp0, &sp4, 0, 0);
}
