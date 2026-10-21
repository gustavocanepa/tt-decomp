typedef int s32;
typedef float f32;

extern "C" void func_002060C0(s32 arg0, s32 arg1, f32 *arg2, s32 arg3, s32 arg4);

extern "C" void func_00205CE0(s32 arg0, f32 fparg0) {
    f32 sp = fparg0;
    func_002060C0(arg0, 0, &sp, 0, 0);
}
