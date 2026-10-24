#include "types.h"

struct RefCounter {
    s32 ref;
};

struct Lst {
    char pad0[0x8];
    s32 *items;
    char pad1[0x8];
    s32 count;
};

struct Owner {
    char pad0[0x2C];
    Lst *lst;
};

extern "C" void func_002ADBF0(void *arg0, int arg1);
extern "C" void func_002B01F8(void *arg0, void *arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void func_002B8370(void *arg0, Owner *arg1) {
    s32 buf0[4];
    Lst *s2;
    s32 *s1;

    func_002B01F8(buf0, (char *)arg0 + 8);
    s2 = arg1->lst;
    s1 = &s2->items[s2->count];
    if (s1 != buf0) {
        s32 newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        s32 oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    s2->count = s2->count + 1;
    func_002ADBF0(buf0, 2);
}
