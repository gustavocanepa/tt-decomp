#include "types.h"

struct RefCounter;

struct Obj {
    char pad0[0x18C];
    s32 h;
    s32 h2;
};

extern "C" void func_00243750(Obj *arg0, void *arg1);
extern "C" void func_001C1380(void *arg0, s32 *arg1);
extern "C" void func_001C13B0(void *arg0, int arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void func_00240208(Obj *self, void *arg1) {
    s32 buf[4];
    s32 zero;
    s32 zero2;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    func_00243750(self, arg1);
    zero = 0;
    func_001C1380(buf, &zero);
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
    func_001C13B0(buf, 2);
    zero2 = 0;
    func_001C1380(buf, &zero2);
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
    func_001C13B0(buf, 2);
}
