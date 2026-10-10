typedef int s32;

extern "C" void func_002A2758(s32 arg0, s32 arg1);

extern "C" s32 func_00292098(s32 arg0, s32 arg1) {
    func_002A2758(arg0, arg1 + 0x3C);
    return arg0;
}
