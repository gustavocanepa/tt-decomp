typedef int s32;

extern "C" void func_0011C918(s32 *arg0);
extern "C" void func_0011DE80(s32 *arg0, s32 arg1);
extern "C" void func_00119168(s32 arg0, s32 *arg1);
extern "C" void func_0011DE28(s32 *arg0, s32 arg1);
extern "C" void func_0011C8C0(s32 *arg0, s32 arg1);

extern "C" void func_00118C58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];

        func_0011C918(buf0);
        func_0011DE80(buf1, arg3);
        func_00119168(buf0[0], buf1);
        func_0011DE28(buf1, 2);
        func_0011C8C0(buf0, 2);
    }
}
