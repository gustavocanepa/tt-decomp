typedef int s32;

extern "C" void func_001DF1F8(void *arg0, int arg1);
extern "C" void func_001DF250(void *arg0, void *arg1);
extern "C" void func_001E5440(s32 arg0, s32 arg1);
extern "C" void func_00202788(void *arg0, int arg1);
extern "C" void func_002027E0(void *arg0, void *arg1);

extern "C" void func_001E0CE8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s0 = arg3;

    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];

        func_001DF250(buf0, (void *)arg1);
        s32 *p1 = buf1;
        func_002027E0(p1, (void *)s0);
        func_001E5440(buf0[0], p1[0]);
        func_00202788(p1, 2);
        func_001DF1F8(buf0, 2);
    }
}
