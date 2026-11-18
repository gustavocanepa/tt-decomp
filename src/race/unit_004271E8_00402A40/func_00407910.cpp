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

extern "C" void func_00407500(void *, s32);
extern "C" s32 func_0040CDD0(void *, s32, u8, u8);

struct func_00407910_arg0 {
    char pad0[0x4D8];
    s32 unk4D8;
};
struct func_00407910_v_s0 {
    char pad0[0x28];
    s64 unk28;
    char pad30[0xFF];
    s8 unk12F;
    s8 unk130;
};
struct func_00407910_arg2 {
    char pad0[0x3];
    u8 unk3;
    char pad4[0x2];
    u8 unk6;
    u8 unk7;
    char pad8[0x2];
    u8 unkA;
};

extern "C" void func_00407910(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    s32 t1;
    s32 t2;
    v_s0 = (char *)arg0 + (((((((struct func_00407910_arg0 *)arg0)->unk4D8 << 1) + ((struct func_00407910_arg0 *)arg0)->unk4D8) << 3) + ((struct func_00407910_arg0 *)arg0)->unk4D8) << 4);
    v_s0 = (char *)v_s0 + 0x8;
    ((struct func_00407910_v_s0 *)v_s0)->unk28 = (s64)arg1;
    func_00407500(arg0, arg2);
    t1 = func_0040CDD0(v_s0, 0x1, ((struct func_00407910_arg2 *)arg2)->unk6, ((struct func_00407910_arg2 *)arg2)->unk3);
    ((struct func_00407910_v_s0 *)v_s0)->unk12F = (s8)t1;
    t2 = func_0040CDD0(v_s0, 0x1, ((struct func_00407910_arg2 *)arg2)->unkA, ((struct func_00407910_arg2 *)arg2)->unk7);
    ((struct func_00407910_v_s0 *)v_s0)->unk130 = (s8)t2;
}
