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

extern "C" void * func_0015A6E8(void *);
extern "C" void * func_00168270(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00168090(void *, s32);
extern "C" void func_0015A690(void *, s32);

extern "C" void MOption__get_slide_playlist(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    p_s2 = buf1;
    func_0015A6E8(p_s2);
    func_00168270(buf0, *(s32 *)((char *)*p_s2 + 0x10) + 0x8a0);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_00168090(buf0, 0x2);
    func_0015A690(p_s2, 0x2);
}
