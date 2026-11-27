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

extern char D_005E4A90[];
extern "C" void func_004A45D0(s32);
extern "C" void func_004F7B74(void *, void *);
extern "C" void func_004F7A30(void *, void *);
extern "C" void func_0047DB20(void *, void *, s32);
extern "C" void func_0041ECD0(s32);

struct func_00178B90_arg0 {
    char pad0[0xB24];
    s32 unkB24;
};

extern "C" void func_00178B90(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 buf6[4];
    s32 buf7[4];
    s32 buf8[4];
    s32 buf9[4];
    s32 buf10[4];
    func_004A45D0(((struct func_00178B90_arg0 *)arg0)->unkB24);
    ((struct func_00178B90_arg0 *)arg0)->unkB24 = 0;
    if (arg2 != 0) {
        func_004F7B74(buf0, arg1);
        func_004F7A30(buf0, &D_005E4A90);
        func_0047DB20(buf9, buf0, 0x1);
        ((struct func_00178B90_arg0 *)arg0)->unkB24 = buf10[0];
        func_0041ECD0(buf10[0]);
    }
}
