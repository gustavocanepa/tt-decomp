typedef int s32;

extern "C" void func_004C1E08(char *, s32, s32, s32, s32, s32, char *);
extern "C" char *func_004C1EB0(char *);
extern "C" void func_004A4D68(s32);
extern "C" void func_004A4DD8(s32);

extern "C" void func_004C1D38(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 lock;
    char *buf;

    lock = (s32)(arg0 + 0x2200);
    func_004A4D68(lock);
    if (arg6 == 0 && *(s32 *)(arg0 + 0x21C8) == 0) {
        buf = arg0 + 0x2100;
        *(s32 *)(arg0 + 0x21C8) = 1;
    } else {
        buf = func_004C1EB0(arg0);
    }
    if (buf != 0) {
        func_004C1E08(arg0, arg1, arg2, arg3, arg4, arg5, buf);
    }
    func_004A4DD8(lock);
}
