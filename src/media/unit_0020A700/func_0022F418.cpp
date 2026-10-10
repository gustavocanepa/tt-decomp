typedef int s32;

extern "C" void func_0022F240(void *arg0, int arg1);
extern "C" void func_0022F298(void *arg0, void *arg1);
extern "C" s32 func_0022F7C8(s32 arg0);
extern "C" void func_00202758(s32 *arg0, s32 *arg1);
extern "C" void func_00202788(s32 *arg0, int arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_0022F418(s32 *arg0, void *arg1) {
    s32 buf1[4];
    s32 buf0[4];
    s32 temp;
    s32 newVal;
    s32 oldVal;

    func_0022F298(buf1, arg1);
    s32 *ptemp = &temp;
    temp = func_0022F7C8(buf1[0]);
    s32 *p0 = buf0;
    func_00202758(p0, ptemp);
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
    func_00202788(p0, 2);
    func_0022F240(buf1, 2);
}
