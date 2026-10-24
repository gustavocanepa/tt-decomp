#include "types.h"

struct Obj {
    char pad[0xA0];
    s64 unkA0;
} __attribute__((aligned(8)));

extern char D_00585A30;

extern "C" s32 func_0040B8A0(void *arg0, s64 arg1);

extern "C" s32 func_0040EE28(Obj *arg0) {
    return func_0040B8A0(&D_00585A30, arg0->unkA0);
}
