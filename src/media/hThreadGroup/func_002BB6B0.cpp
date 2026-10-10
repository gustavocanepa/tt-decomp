typedef int s32;

extern "C" void func_002BB560(s32 *arg0);
extern "C" void func_002B15D0(s32 *arg0, s32 arg1);
extern "C" void func_002BBB50(s32 arg0, s32 *arg1);
extern "C" void func_002B1578(s32 *arg0, s32 arg1);
extern "C" void func_002BB508(s32 *arg0, s32 arg1);

extern "C" void func_002BB6B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];

        func_002BB560(buf0);
        func_002B15D0(buf1, arg3);
        func_002BBB50(buf0[0], buf1);
        func_002B1578(buf1, 2);
        func_002BB508(buf0, 2);
    }
}
