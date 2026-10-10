#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020F120();                            /* extern */

struct func_0020EF28_arg0 {
    char pad0[0x80];
    s32 unk80;
    char pad84[0x28];
    s32 unkAC;
};

s32 func_0020EF28(struct func_0020EF28_arg0 *arg0) {
    if (arg0->unkAC & 0x40000) {
        func_0020F120();
    }
    return arg0->unk80 != 0;
}
