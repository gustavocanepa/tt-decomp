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

extern char D_00602500[];
extern "C" void func_0045A3A8(void *, s32);
extern "C" s32 func_004A8368(void *);
extern "C" void func_0045A560(void *, void *, s32);
extern "C" void func_0045A330(void *, s32);

struct func_00457388_arg1 {
    char pad0[0x1C];
    u8 unk1C;
    u8 unk1D;
    char pad1E[0x6];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
};

extern "C" void func_00457388(s32 *arg0, struct func_00457388_arg1 *arg1) {
    char *v_s0;
    v_s0 = (char *)arg0 + 0x85c;
    func_0045A3A8(v_s0, (0 | 0xffe0));
    func_0045A3A8(v_s0, 0x10);
    func_0045A560(v_s0, &D_00602500, func_004A8368(&D_00602500) + 0x1);
    func_0045A330(v_s0, arg1->unk1C);
    func_0045A330(v_s0, arg1->unk1D);
    func_0045A330(v_s0, arg1->unk24);
    func_0045A3A8(v_s0, arg1->unk28);
    func_0045A3A8(v_s0, arg1->unk2C);
    func_0045A330(v_s0, arg1->unk30);
    func_0045A330(v_s0, arg1->unk34);
}
