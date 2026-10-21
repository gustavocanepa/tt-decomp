typedef int s32;

struct Obj {
    char pad0[0xB8];
    s32 z;
    s32 h;
    s32 h2;
};

extern "C" void func_0020B408(void);
extern "C" void func_00234550(void *arg0, s32 *arg1);
extern "C" void func_00234580(void *arg0, int arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_00235628(Obj *self) {
    s32 buf[4];
    s32 zero;
    s32 zero2;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    func_0020B408();
    self->z = 0;
    zero = 0;
    func_00234550(buf, &zero);
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
    func_00234580(buf, 2);
    zero2 = 0;
    func_00234550(buf, &zero2);
    dst = &self->h2;
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
    func_00234580(buf, 2);
}
