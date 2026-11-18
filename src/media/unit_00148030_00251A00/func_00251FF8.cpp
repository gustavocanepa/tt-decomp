#include "types.h"

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)(((VObj *)o)->vtbl + 0x70);
    return e->fn(o + e->delta);
}

extern "C" void *func_00251678(void *, void *) throw();
extern "C" void func_00251620(void *, s32) throw();
extern "C" void func_0029B380(void *, f32);
extern "C" void func_00299AB0(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

struct Ctx { char pad[0x120]; f32 v; };

extern "C" void func_00251FF8(s32 *arg0, void *arg1, s32 mode, s32 *arg3) {
    s32 buf0[4];
    s32 h[4];
    if (mode == 0) {
        func_00251678(buf0, arg1);
        s32 *p = h;
        func_0029B380(p, ((Ctx *)buf0[0])->v);
        if (arg0 != p) {
            s32 nv = p[0];
            if (nv != 0)
                func_002C0FE8(nv);
            if (arg0[0] != 0)
                func_002C1050(arg0[0]);
            arg0[0] = nv;
        }
        func_00299AB0(p, 2);
        func_00251620(buf0, 2);
    } else if (mode == 1) {
        func_00251678(buf0, arg1);
        Ctx *c = (Ctx *)buf0[0];
        f32 x = vcall_60((char *)arg3[0]);
        if (x < 0.0f)
            x = 0.0f;
        if (x > 1.0f)
            x = 1.0f;
        c->v = x;
        func_00251620(buf0, 2);
    }
}
