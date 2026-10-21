typedef int s32;

struct RefCounter;

struct Obj {
    char pad0[0x120];
    s32 h;
    s32 h2;
};

extern "C" void func_0020B2C8(Obj *arg0, void *arg1);
extern "C" void func_0029B458(void *arg0, s32 *arg1);
extern "C" void func_0029B488(void *arg0, int arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void func_001EB620(Obj *self, void *arg1) {
    s32 buf[4];
    s32 zero;
    s32 zero2;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    func_0020B2C8(self, arg1);
    zero = 0;
    func_0029B458(buf, &zero);
    dst = &self->h;
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *dst = newVal;
    }
    func_0029B488(buf, 2);
    zero2 = 0;
    func_0029B458(buf, &zero2);
    dst = &self->h2;
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *dst = newVal;
    }
    func_0029B488(buf, 2);
}
