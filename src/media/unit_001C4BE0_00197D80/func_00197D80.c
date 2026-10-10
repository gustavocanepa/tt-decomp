#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F7B74(s32);                         /* extern */

extern char D_005AC2F8[];
struct func_00197D80_arg0 {
    s32 unk0;
    s8 unk4;
    char pad5[0x3F];
    s32 unk44;
};

s32 func_00197D80(void *arg0, s32 arg1, s32 arg2) {
    ((struct func_00197D80_arg0 *)arg0)->unk0 = (s32)D_005AC2F8;
    if (arg1 != 0) {
        func_004F7B74(arg0 + 4);
    } else {
        ((struct func_00197D80_arg0 *)arg0)->unk4 = 0;
    }
    ((struct func_00197D80_arg0 *)arg0)->unk44 = arg2;
}
