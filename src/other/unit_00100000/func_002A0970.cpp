typedef int s32;

extern "C" void func_002A0438(void *arg0, int arg1);
extern "C" void func_002A0490(void *arg0, void *arg1);
extern "C" s32 func_002A10B8(char *arg0);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_002A0970(s32 *arg0, void *arg1, s32 arg2) {
    char *h[4];
    if (arg2 == 0) {
        s32 buf[4];
        s32 *buf0;
        s32 newVal;
        s32 oldVal;
        s32 v;
        func_002A0490(h, arg1);
        v = func_002A10B8(h[0]);
        buf0 = buf;
        func_0029EA18(buf0, v);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_0029CEF0(buf0, 2);
        func_002A0438(h, 2);
    }
}
