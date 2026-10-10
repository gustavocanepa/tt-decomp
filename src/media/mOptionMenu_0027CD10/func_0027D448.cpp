typedef int s32;

struct Obj {
    char pad0[0x118];
    s32 h;
};

extern "C" void func_0029B458(void *arg0, s32 *arg1);
extern "C" void func_0029B488(void *arg0, int arg1);
extern "C" void func_0020B2C8(Obj *self);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_0027D448(Obj *self) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    func_0020B2C8(self);
    zero = 0;
    func_0029B458(buf, &zero);
    dst = &self->h;
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *dst = newVal;
    }
    func_0029B488(buf, 2);
}
