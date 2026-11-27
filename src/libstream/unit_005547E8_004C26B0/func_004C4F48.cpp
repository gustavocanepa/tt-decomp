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

struct S00659988 {
    const char *name;
};

extern char D_004C7988[];
extern char D_005A0B88[];
extern s64 D_006137B0;
extern "C" void func_004A4930(void *);
extern "C" void func_004C7A48(void *, s64);
extern "C" void func_004C73F8(s32, void *, void *, void *, s32);
extern "C" void func_004A4970(void *);

extern "C" void func_004C4F48(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    char *v_s2;
    v_s2 = (char *)&D_005A0B88;
    func_004A4930(v_s2);
    func_004C7A48(buf0, D_006137B0);
    buf3[0] = (buf3[0] | 0x1);
    buf1[0] = 0x5;
    if (arg1 != 0) {
        buf1[3] = (s32)arg1;
        buf3[0] = (buf3[0] | 0x9);
    }
    func_004C73F8(buf0[0], buf0, &D_004C7988, arg0, 0);
    func_004A4970(v_s2);
}
