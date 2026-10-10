typedef int s32;

extern "C" void func_001803E8(s32 *arg0);
extern "C" s32 func_00182C28(s32 arg0);
extern "C" void func_0029EA18(s32 *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_0029CEF0(s32 *arg0, s32 arg1);
extern "C" void func_00180390(s32 *arg0, s32 arg1);

extern "C" void func_00181338(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 newVal;
    s32 oldVal;

    func_001803E8(p1);
    func_0029EA18(buf0, func_00182C28(*p1));
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
    func_00180390(p1, 2);
}
