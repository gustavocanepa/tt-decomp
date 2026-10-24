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

extern "C" void func_001C04F8(void *, void *, s32, void *, void *);
extern "C" void func_001E4E80(void *, void *);
extern "C" void func_001C0228(void *, s32);

extern "C" void func_001EBB88(s32 *arg0, void *arg1) {
    s32 buf0[4];
    char *v0 = (char *)arg0 + 0x124;
    if (*(s32 *)(char *)v0 != 0) {
        func_001C04F8(buf0, v0, 0x2, arg1, arg0);
        func_001E4E80(arg1, buf0);
        func_001C0228(buf0, 0x2);
    }
}
