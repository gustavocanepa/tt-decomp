#include "types.h"
struct VEntry_60 { short delta; short index; float (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline float vcall_60(char *o) {
    VEntry_60 *e = &((VObj_60 *)o)->vtbl[14];
    return e->fn(o + e->delta);
}
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);

struct HFloat {
    char pad0[0x10];
    float value;
};

extern "C" void func_0029A328(HFloat *self, s32 *result, s32 a2, s32 a3, char **other) {
    s32 buf[4];
    float f = vcall_60(*other);
    func_0029EA18(buf, self->value < f);
    if (result != buf) {
        s32 newVal = buf[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        s32 oldVal = *result;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *result = newVal;
    }
    func_0029CEF0(buf, 2);
}
