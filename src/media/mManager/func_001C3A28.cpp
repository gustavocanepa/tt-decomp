typedef int s32;

extern "C" void func_001C2A20(void *arg0, int arg1);
extern "C" void func_001C2A78(void *arg0, void *arg1);
extern "C" s32 func_001C51E8(s32 arg0);
extern "C" void func_001FCAD0(s32 *arg0, s32 *arg1);
extern "C" void func_001FCB00(s32 *arg0, int arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_001C3A28(s32 *arg0, void *arg1) {
    s32 buf1[4];
    s32 buf0[4];
    s32 temp;
    s32 newVal;
    s32 oldVal;

    func_001C2A78(buf1, arg1);
    s32 *ptemp = &temp;
    temp = func_001C51E8(buf1[0]);
    s32 *p0 = buf0;
    func_001FCAD0(p0, ptemp);
    if (arg0 != p0) {
        newVal = *p0;
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_001FCB00(p0, 2);
    func_001C2A20(buf1, 2);
}
