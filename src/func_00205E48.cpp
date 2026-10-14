typedef int s32;
typedef float f32;

extern "C" void func_002060C0(s32 arg0, s32 arg1, s32 arg2, f32 *arg3, f32 *arg4);

extern "C" void func_00205E48(s32 arg0, f32 fparg0, f32 fparg1) {
    f32 sp0;
    f32 sp4;

    sp0 = fparg0;
    sp4 = fparg1;
    func_002060C0(arg0, 0, 0, &sp0, &sp4);
}
