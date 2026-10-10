typedef int s32;

extern "C" void func_002027E0(s32 *arg0);
extern "C" s32 func_00206DF8(s32 arg0);
extern "C" void func_002A7578(s32 *arg0, s32 *arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_002A75A8(s32 *arg0, s32 arg1);
extern "C" void func_00202788(s32 *arg0, s32 arg1);

extern "C" void func_00203490(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 temp;
    s32 *ptemp = &temp;
    s32 newVal;
    s32 oldVal;

    func_002027E0(p1);
    temp = func_00206DF8(*p1);
    func_002A7578(buf0, ptemp);
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
    func_002A75A8(buf0, 2);
    func_00202788(p1, 2);
}
