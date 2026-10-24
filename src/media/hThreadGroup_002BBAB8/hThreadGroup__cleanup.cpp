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

extern "C" void func_002A9980(void);
extern "C" void func_002B1548(void *, void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_002B1578(void *, s32);
extern "C" void func_0054F6C0(void *);

extern "C" void hThreadGroup__cleanup(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    p_s1 = (s32 *)((char *)arg0 + 0x10);
    func_002A9980();
    buf1[0] = 0;
    func_002B1548(buf0, buf1);
    if ((char *)p_s1 != (char *)buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *p_s1;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *p_s1 = newVal;
    }
    func_002B1578(buf0, 0x2);
    func_0054F6C0((char *)arg0 + 0x14);
}
