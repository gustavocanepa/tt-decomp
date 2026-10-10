typedef int s32;

struct Obj {
    char pad0[0xD8];
    s32 h;
};

extern "C" void func_002293E0(void *arg0, s32 *arg1);
extern "C" void func_00229410(void *arg0, int arg1);
extern "C" void func_001B9BD8(Obj *self);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_001DEB50(Obj *self) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    func_001B9BD8(self);
    zero = 0;
    func_002293E0(buf, &zero);
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
    func_00229410(buf, 2);
}
