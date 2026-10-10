typedef int s32;

extern "C" s32 func_003542A0(s32 arg0, s32 arg1);
extern "C" void func_00355D68(s32 arg0, s32 arg1);

extern "C" void func_00355D30(s32 arg0) {
    s32 s0 = arg0;
    s32 v0 = func_003542A0(arg0, 1);
    func_00355D68(s0, v0);
}
