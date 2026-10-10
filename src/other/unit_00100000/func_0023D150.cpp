typedef int s32;

extern "C" void func_0023D980(s32 *arg0);
extern "C" void func_002ADC48(s32 *arg0, s32 arg1);
extern "C" void func_0023D768(s32 arg0, s32 *arg1);
extern "C" void func_002ADBF0(s32 *arg0, s32 arg1);
extern "C" void func_0023D928(s32 *arg0, s32 arg1);

extern "C" void func_0023D150(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];

        func_0023D980(buf0);
        func_002ADC48(buf1, arg3);
        func_0023D768(buf0[0], buf1);
        func_002ADBF0(buf1, 2);
        func_0023D928(buf0, 2);
    }
}
