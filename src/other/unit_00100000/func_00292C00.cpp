typedef int s32;

extern "C" void func_002931B0(s32 arg0, s32 arg1);

extern "C" s32 func_00292C00(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    func_002931B0(s0, arg1 + 0x78);
    return s0;
}
