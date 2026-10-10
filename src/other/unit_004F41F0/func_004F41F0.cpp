typedef int s32;

extern "C" void func_004A59F0();
extern "C" s32 func_004F40F8();
extern "C" s32 func_004FA830(s32 arg0);

extern "C" void func_004F41F0(void) {
    s32 s0 = func_004F40F8();
    if (s0 != -1) {
        while (func_004FA830(s0) == -1) {
            func_004A59F0();
        }
    }
}
