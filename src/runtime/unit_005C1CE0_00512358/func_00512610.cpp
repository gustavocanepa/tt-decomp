typedef int s32;

extern "C" void func_00139BC8(s32 arg0, s32 arg1);

extern "C" s32 func_00512610(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    func_00139BC8(s0, arg1 + 0x308);
    return s0;
}
