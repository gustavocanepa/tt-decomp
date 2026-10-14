typedef int s32;
typedef float f32;

extern "C" void func_00205E78(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4);

extern "C" f32 func_00205CB0(s32 arg0) {
    f32 sp[4];
    func_00205E78(arg0, 0, sp, 0, 0);
    return sp[0];
}
