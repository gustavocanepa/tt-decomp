typedef int s32;

struct RefCounter;

extern "C" void func_00296A20(void *arg0, int arg1);
extern "C" void func_00296A78(void *arg0, void *arg1);
extern "C" s32 func_00297738(s32 *arg0, s32 *arg1);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void func_00296CE0(s32 *arg0, void *arg1, void *arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    s32 r;

    func_00296A78(buf0, arg1);
    func_00296A78(buf1, (void *)arg3);
    r = func_00297738(buf0, buf1);
    p_s2 = buf2;
    func_0029EA18(p_s2, (void *)r);
    if (arg0 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(p_s2, 2);
    func_00296A20(buf1, 2);
    func_00296A20(buf0, 2);
}
