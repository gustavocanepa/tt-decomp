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

extern "C" void func_00123F58(void *);
extern "C" void func_00139BC8(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00139BE0(void *, s32);
extern "C" void func_00123F00(void *, s32);

extern "C" void MCarFace__get_car_model(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    func_00123F58(buf0);
    p_s2 = buf1;
    func_00139BC8(p_s2, buf0[0] + 0x308);
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
    func_00139BE0(p_s2, 0x2);
    func_00123F00(buf0, 0x2);
}
