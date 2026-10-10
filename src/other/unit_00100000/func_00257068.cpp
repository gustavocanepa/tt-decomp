typedef int s32;

extern "C" void func_002A7590(s32 arg0, s32 arg1);

extern "C" s32 func_00257068(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    func_002A7590(s0, arg1 + 0x140);
    return s0;
}
