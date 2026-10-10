typedef int s32;

extern "C" s32 func_0040B910(void *arg0, s32 arg1, void *arg2);
extern "C" char *func_0040B8A0(void *arg0, s32 arg1);
extern "C" void func_004F7B74(void *arg0, const char *arg1);
extern char D_00585A30[];

extern "C" void func_0040EA08(s32 arg0, void *arg1) {
    char buf[0x10];

    if (arg0 != -1 && func_0040B910(D_00585A30, arg0, buf) != 0) {
        func_004F7B74(arg1, func_0040B8A0(D_00585A30, arg0));
    }
}
