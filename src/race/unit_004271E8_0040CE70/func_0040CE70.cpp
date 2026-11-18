#include "types.h"

struct Obj {
    s64 unk0;
} __attribute__((aligned(8)));

extern char D_00585A30;

extern "C" s32 func_0040B8A0(void *arg0, s64 arg1);

extern "C" s32 func_0040CE70(Obj *arg0) {
    return func_0040B8A0(&D_00585A30, arg0->unk0);
}
