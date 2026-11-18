#include "types.h"

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, s32, f32);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_00220970(void *arg0, int arg1);
extern "C" void func_002209C8(void *arg0, void *arg1);
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_00299B08(void *arg0, void *arg1);
extern "C" f32 func_0029B188(void *arg0);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029CF48(void *arg0, void *arg1);
extern "C" s32 func_0029E9F0(s32 arg0);

extern "C" void func_00220E90(void *arg0, void *arg1, s32 arg2, void *arg3)
{
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 v_s3;
    s32 *p_s2;
    s32 *p_s0;
    if (arg2 > 0) {
        v_s3 = -1;
        func_002209C8(buf0, arg1);
        p_s2 = buf1;
        func_00299B08(p_s2, arg3);
        p_s0 = buf2;
        if (!(arg2 < 2)) {
            func_0029CF48(p_s0, (char *)arg3 + 4);
            v_s3 = func_0029E9F0(*p_s0);
            func_0029CEF0(p_s0, 2);
        }
        VObj *o = (VObj *)buf0[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x2A0);
        char *self = (char *)o + e->delta;
        f32 f = func_0029B188((void *)*p_s2);
        e->fn(self, v_s3, f);
        func_00299AB0(p_s2, 2);
        func_00220970(buf0, 2);
    }
}
