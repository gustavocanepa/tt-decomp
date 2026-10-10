typedef int s32;

extern "C" void func_002830D0(char *, s32, s32);

extern "C" void func_00283008(char *arg0, s32 arg1) {
    func_002830D0(arg0, arg1, *(s32 *)(arg0 + 0xF0));
}
