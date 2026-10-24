#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, const char *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

extern char D_005E9BB0[];

extern "C" void func_001DF1F8(void *arg0, int arg1);
extern "C" void func_001DF250(void *arg0, void *arg1);
extern "C" void func_002ADBF0(void *arg0, int arg1);
extern "C" void func_002ADC48(void *arg0, void *arg1);
extern "C" u8 *func_002AFE68(u8 *arg0);

extern "C" void func_001E1130(void *arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];
        s32 *p_s2;
        func_001DF250(buf0, arg1);
        p_s2 = buf1;
        func_002ADC48(p_s2, arg3);
        VObj *o = (VObj *)buf0[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x288);
        char *self = (char *)o + e->delta;
        Str *s = (Str *)func_002AFE68((u8 *)p_s2[0]);
        const char *v = D_005E9BB0;
        s32 len = ((Rep *)s->p)[-1].len;
        if (len != 0) {
            s->p[len] = 0;
            v = s->p;
        }
        e->fn(self, v);
        func_002ADBF0(p_s2, 2);
        func_001DF1F8(buf0, 2);
    }
}
