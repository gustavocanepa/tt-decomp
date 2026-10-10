#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00205E78(s32, s32, s32, s32, s32);     /* extern */

struct func_0025DC48_arg0 {
    char pad0[0x4C];
    s32 unk4C;
};

s32 func_0025DC48(void *arg0, s32 arg1) {
    ((struct func_0025DC48_arg0 *)arg0)->unk4C = arg1;
    if (arg1 != 0) {
        func_00205E78(arg1, arg0 + 0x54, arg0 + 0x58, arg0 + 0x5C, arg0 + 0x60);
    }
}
