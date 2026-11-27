#include "types.h"

struct VEntry_2C3830 { s16 delta; s16 index; float (*fn)(void *); };
struct Obj_2C3830 { s32 m0; VEntry_2C3830 *vtbl; };

extern "C" void func_002655D8(void *arg0, void *arg1);
extern "C" void func_00265580(void *arg0, s32 arg1);

extern "C" void func_00265EC0(void *a0, void *a1, s32 a2, Obj_2C3830 **a3) {
    s32 buf[4];
    if (a2 > 0) {
        func_002655D8(buf, a1);
        Obj_2C3830 *obj = *a3;
        char *p = (char *)buf[0] + 0x18;
        VEntry_2C3830 *e = &obj->vtbl[14];
        float r = e->fn((char *)obj + e->delta);
        *(float *)p = r;
        func_00265580(buf, 2);
    }
}
