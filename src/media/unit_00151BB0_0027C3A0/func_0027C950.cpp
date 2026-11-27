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

extern "C" void func_0027BEF0(void *);
extern "C" s32 func_0027DFF8(s32);
extern "C" void func_002A7578(void *, void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_0027BE98(void *, s32);

extern "C" void func_0027C950(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s2;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    func_0027BEF0(buf0);
    t1 = func_0027DFF8(buf0[0]);
    p_s2 = buf1;
    if (t1 != 0) {
        buf2[0] = t1;
        func_002A7578(p_s2, buf2);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_002A75A8(p_s2, 0x2);
    }
    func_0027BE98(buf0, 0x2);
}
