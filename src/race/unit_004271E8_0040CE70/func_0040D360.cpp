#include "types.h"

struct Obj {
    char pad[0x10];
    s64 unk10;
} __attribute__((aligned(8)));

extern char D_00585A30;

extern "C" s32 func_0040B9F8(void *arg0, s64 arg1);

extern "C" s32 func_0040D360(Obj *arg0) {
    return func_0040B9F8(&D_00585A30, arg0->unk10);
}
