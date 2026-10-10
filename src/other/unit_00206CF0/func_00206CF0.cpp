typedef int s32;
typedef float f32;

extern "C" f32 func_00205C50(void);
extern "C" s32 func_00206CA0(void *out, f32 a, f32 b);
extern "C" void func_00205C80(s32 arg0, f32 arg1);

extern "C" s32 func_00206CF0(s32 arg0, f32 fparg0, f32 fparg1) {
    f32 sp0;
    s32 temp_s0;

    sp0 = func_00205C50();
    temp_s0 = func_00206CA0(&sp0, fparg0, fparg1);
    func_00205C80(arg0, sp0);
    return temp_s0;
}
