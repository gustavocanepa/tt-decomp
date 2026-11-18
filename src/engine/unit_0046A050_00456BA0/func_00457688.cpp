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

extern "C" void func_0045A3A8(void *, s32);
extern "C" void func_0045A330(void *, s32);

extern "C" void func_00457688(s32 *arg0) {
    char *v_s0;
    v_s0 = (char *)arg0 + 0x85c;
    func_0045A3A8(v_s0, (0 | 0xffda));
    func_0045A3A8(v_s0, 0xc);
    func_0045A330(v_s0, 0x3);
    func_0045A330(v_s0, 0);
    func_0045A330(v_s0, 0);
    func_0045A330(v_s0, 0x1);
    func_0045A330(v_s0, 0x11);
    func_0045A330(v_s0, 0x2);
    func_0045A330(v_s0, 0x11);
    func_0045A330(v_s0, 0);
    func_0045A330(v_s0, 0x3f);
    func_0045A330(v_s0, 0);
}
