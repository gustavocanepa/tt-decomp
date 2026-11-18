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

extern "C" void func_0011C918(void *);
extern "C" void func_0029CF48(void *, void *);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_0011C8C0(void *, s32);

struct MLoggerControl__setSpeedCurrent_v_s1 {
    char pad0[0x9C];
    s32 unk9C;
};
struct MLoggerControl__setSpeedCurrent_arg3 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" void MLoggerControl__setSpeedCurrent(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 v_s1;
    if (arg2 >= 0x2) {
        func_0011C918(buf0);
        p_s0 = buf1;
        func_0029CF48(p_s0, arg3);
        v_s1 = func_0029E9F0(*p_s0);
        func_0029CEF0(p_s0, 0x2);
        v_s1 = (v_s1 << 2);
        v_s1 = (v_s1 + buf0[0]);
        ((struct MLoggerControl__setSpeedCurrent_v_s1 *)v_s1)->unk9C = ((struct MLoggerControl__setSpeedCurrent_arg3 *)arg3)->unk4;
        func_0011C8C0(buf0, 0x2);
    }
}
