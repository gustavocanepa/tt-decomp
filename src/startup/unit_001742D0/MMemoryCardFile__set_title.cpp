#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Holder_174650 {
    char pad0[0x10];
    char *obj;
};

struct VObj_174650 {
    char pad0[0x4C];
    char *vtbl;
};

struct VEntry_174650 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, const char *);
};

extern char D_005E27D0[];

extern "C" void func_00151AE8(void *arg0, void *arg1);
extern "C" void func_002ADC48(void *arg0, void *arg1);
extern "C" u8 *func_002AFE68(u8 *arg0);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_0029CEF0(void *arg0, s32 arg1);
extern "C" void func_002ADBF0(void *arg0, s32 arg1);
extern "C" void func_00151A90(void *arg0, s32 arg1);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_005E27D0;
    }
    s->p[len] = 0;
    return s->p;
}

extern "C" void MMemoryCardFile__set_title(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s3;
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_00151AE8(buf0, arg1);
        p_s3 = buf1;
        func_002ADC48(p_s3, arg3);
        {
            u8 *key = (u8 *)p_s3[0];
            VEntry_174650 *e;
            char *obj;
            char *self;
            Str *r;
            s32 t1;
            obj = ((Holder_174650 *)buf0[0])->obj;
            e = (VEntry_174650 *)(((VObj_174650 *)obj)->vtbl + 0x68);
            self = obj + e->delta;
            r = (Str *)func_002AFE68(key);
            t1 = e->fn(self, c_str(r));
            p_s1 = buf2;
            func_0029EA18(p_s1, t1 != 0);
        }
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_0029CEF0(p_s1, 0x2);
        func_002ADBF0(p_s3, 0x2);
        func_00151A90(buf0, 0x2);
    }
}
