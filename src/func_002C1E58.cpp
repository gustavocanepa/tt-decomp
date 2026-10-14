typedef int s32;

extern "C" void func_002A96F0(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_002C1E58(s32 arg0, s32 arg1, s32 *arg2) {
    func_002A96F0(*arg2, arg1, arg0 + 0xC);
}
