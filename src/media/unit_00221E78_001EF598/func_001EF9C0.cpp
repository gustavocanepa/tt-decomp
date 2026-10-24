#include "types.h"

struct RefCounter;

struct Obj {
    char pad0[4];
    char *vt;
};

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

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, const char *, const char *, s32);
};

extern char D_005EA618[];

extern "C" void func_001EEF60(void *arg0, int arg1);
extern "C" void func_001EEFB8(void *arg0, void *arg1);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002ADBF0(void *arg0, int arg1);
extern "C" void func_002ADC48(void *arg0, void *arg1);
extern "C" u8 *func_002AFE68(u8 *arg0);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_005EA618;
    }
    s->p[len] = 0;
    return s->p;
}

extern "C" void func_001EF9C0(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s6;
    s32 *p_s5;
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;

    if (arg2 >= 0x2) {
        func_001EEFB8(buf0, arg1);
        p_s6 = buf1;
        func_002ADC48(p_s6, arg3);
        p_s5 = buf2;
        func_002ADC48(p_s5, (char *)arg3 + 0x4);
        {
            char *obj;
            VEntry *e;
            char *self;
            Str *k;
            Str *r;
            s32 len;
            s32 t1;

            k = (Str *)func_002AFE68((u8 *)p_s5[0]);
            len = ((Rep *)k->p)[-1].len;
            obj = (char *)buf0[0];
            e = (VEntry *)(((Obj *)obj)->vt + 0x1E8);
            self = obj + e->delta;
            r = (Str *)func_002AFE68((u8 *)p_s6[0]);
            t1 = e->fn(self, c_str(r), c_str(k), len);
            if (t1 >= 0) {
                p_s1 = buf3;
                func_0029EA18(p_s1, (void *)1);
                if (arg0 != p_s1) {
                    newVal = *p_s1;
                    if (newVal != 0) {
                        func_002C0FE8((RefCounter *)newVal);
                    }
                    oldVal = *arg0;
                    if (oldVal != 0) {
                        func_002C1050((RefCounter *)oldVal);
                    }
                    *arg0 = newVal;
                }
                func_0029CEF0(p_s1, 0x2);
            } else {
                p_s1 = buf3;
                func_0029EA18(p_s1, (void *)0);
                if (arg0 != p_s1) {
                    newVal = *p_s1;
                    if (newVal != 0) {
                        func_002C0FE8((RefCounter *)newVal);
                    }
                    oldVal = *arg0;
                    if (oldVal != 0) {
                        func_002C1050((RefCounter *)oldVal);
                    }
                    *arg0 = newVal;
                }
                func_0029CEF0(p_s1, 0x2);
            }
        }
        func_002ADBF0(p_s5, 0x2);
        func_002ADBF0(p_s6, 0x2);
        func_001EEF60(buf0, 0x2);
    }
}
