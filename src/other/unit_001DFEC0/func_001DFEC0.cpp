typedef int s32;

extern "C" void func_001DF250(s32 *arg0);
extern "C" void func_0022F298(s32 *arg0, s32 arg1);
extern "C" void func_001E4E80(s32 arg0, s32 *arg1);
extern "C" void func_0022F240(s32 *arg0, s32 arg1);
extern "C" void func_001DF1F8(s32 *arg0, s32 arg1);

extern "C" void func_001DFEC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];

        func_001DF250(buf0);
        func_0022F298(buf1, arg3);
        func_001E4E80(buf0[0], buf1);
        func_0022F240(buf1, 2);
        func_001DF1F8(buf0, 2);
    }
}
