#include "types.h"

struct VEntry_2C3A28 { s16 delta; s16 index; s32 (*fn)(void *); };
struct Obj_2C3A28 { s32 m0; VEntry_2C3A28 *vtbl; };

extern "C" void func_0018ACD8(void *arg0, void *arg1);
extern "C" void func_0018AC80(void *arg0, s32 arg1);

extern "C" void func_0018FCF8(void *a0, void *a1, s32 a2, Obj_2C3A28 **a3) {
    s32 buf[4];
    if (a2 > 0) {
        func_0018ACD8(buf, a1);
        Obj_2C3A28 *obj = *a3;
        char *p = (char *)buf[0] + 0x2A0;
        VEntry_2C3A28 *e = &obj->vtbl[13];
        s32 r = e->fn((char *)obj + e->delta);
        *(s32 *)(p + 0x138) = r;
        func_0018AC80(buf, 2);
    }
}
