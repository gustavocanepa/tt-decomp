#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00408B58(s32);                             /* extern */
s32 func_0040CFE0(s32);                             /* extern */
s32 func_00411ED0(void *, s32);                 /* extern */

struct func_00132460_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00132460(void *arg0) {
    s32 temp_v0;

    temp_v0 = ((struct func_00132460_arg0 *)arg0)->unk14;
    if (temp_v0 != 0) {
        func_00411ED0(arg0 + 0x18, func_0040CFE0(func_00408B58(temp_v0)));
    }
}
