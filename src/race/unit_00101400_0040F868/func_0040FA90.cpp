#include "types.h"

struct S {
    char pad[0x5CA8];
    void *unk5CA8;
};

extern "C" s32 func_00411AA8(void *);

extern "C" s32 func_0040FA90(s32 arg0) {
    if (arg0 >= 6) {
        return -1;
    }
    struct S *p = (struct S *)(0x580000 + arg0 * 4);
    if (p->unk5CA8 == 0) {
        return -1;
    }
    return func_00411AA8(p->unk5CA8);
}
