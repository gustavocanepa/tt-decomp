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

extern char D_005EA700[];
extern char D_005EA708[];
extern "C" void func_004A6500(void *, void *, void *, void *);
extern "C" s32 func_004FF970(void *, s32, s32);
extern "C" s32 func_00500228(s32, s32, void *);
extern "C" void func_004FFC00(s32);

extern "C" s32 mStorageHD__write(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 buf6[4];
    s32 buf7[4];
    s32 v_s2;
    s32 v_s0;
    func_004A6500(buf0, &D_005EA700, &D_005EA708, arg1);
    v_s2 = func_004FF970(buf0, 0x202, 0x1a4);
    if (v_s2 >= 0) {
        v_s0 = func_00500228(v_s2, arg2, arg3);
        func_004FFC00(v_s2);
        return v_s0;
    }
    return -0x1;
}
