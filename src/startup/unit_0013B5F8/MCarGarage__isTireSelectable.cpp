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

extern "C" void func_00128470(void *);
extern "C" s32 func_001324D8(s32);
extern "C" s32 func_00408B58(s32);
extern "C" s32 func_0040CFE0(s32);
extern "C" s32 func_00410AE8(s32, void *);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_00128418(void *, s32);

extern "C" void MCarGarage__isTireSelectable(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 buf6[4];
    s32 *p_s3;
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    p_s3 = buf5;
    func_00128470(p_s3);
    if (func_00410AE8(func_0040CFE0(func_00408B58(func_001324D8(*p_s3))), buf0) != 0) {
        p_s2 = buf6;
        func_0029EA18(p_s2, *(u8 *)((char *)buf3 + 0x0) != 0);
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
        func_0029CEF0(p_s2, 0x2);
    } else {
        p_s2 = buf6;
        func_0029EA18(p_s2, 0);
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
        func_0029CEF0(p_s2, 0x2);
    }
    func_00128418(p_s3, 0x2);
}
