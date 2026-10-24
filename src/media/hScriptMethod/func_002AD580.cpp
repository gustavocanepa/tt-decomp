#include "types.h"

struct Obj {
    char pad0[0xC];
    s32 h;
};

extern "C" void func_00297888(void *arg0, s32 *arg1);
extern "C" void func_002978B8(void *arg0, int arg1);
extern "C" void func_002C0F40(Obj *self);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_002AD580(Obj *self) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    func_002C0F40(self);
    zero = 0;
    func_00297888(buf, &zero);
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
    func_002978B8(buf, 2);
}
