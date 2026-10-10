typedef int s32;

extern "C" void func_003A5E98(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_0031AA88(s32 arg0, s32 arg1, s32 arg2) {
    s32 k = 0x1B4;
    func_003A5E98(arg0 + arg1 * k + 0xF8, arg2, 1);
}
