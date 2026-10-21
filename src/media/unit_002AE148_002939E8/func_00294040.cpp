#include "types.h"

struct RefCounter;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
static inline s32 vcall(char *o) {
    VEntry *e = (VEntry *)(((VObj *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}

extern "C" void func_00295C18(void *arg0, int arg1);
extern "C" void func_00296240(void *arg0, void *arg1, void *arg2);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void func_00294040(void *a0, s32 *result, s32 a2, s32 a3, char **other) {
    s32 buf[4];
    s32 v = vcall(*other);
    func_00296240(buf, (void *)a2, (void *)v);
    if (result != buf) {
        s32 newVal = buf[0];
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        s32 oldVal = *result;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *result = newVal;
    }
    func_00295C18(buf, 2);
}
