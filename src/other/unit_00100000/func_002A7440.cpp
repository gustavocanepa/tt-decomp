typedef int s32;

extern "C" void func_002A77A8(void);

extern "C" s32 func_002A7440(s32 arg0, s32 arg1) {
    s32 s0 = arg0;

    if (s0 != arg1) {
        func_002A77A8();
    }
    return s0;
}
