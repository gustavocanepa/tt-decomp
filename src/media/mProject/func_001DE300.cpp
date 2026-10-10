typedef int s32;

extern "C" void func_002293F8(s32 arg0, s32 arg1);

extern "C" s32 func_001DE300(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    func_002293F8(s0, arg1 + 0xD8);
    return s0;
}
