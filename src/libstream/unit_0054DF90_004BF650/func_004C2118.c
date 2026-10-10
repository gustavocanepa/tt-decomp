#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */
s32 func_004F4500(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DB1E8[];
struct func_004C2118_arg0 {
    char pad0[0x38];
    s32 unk38;
    s32 unk3C;
};

void func_004C2118(struct func_004C2118_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk38 = (s32)D_005DB1E8;
    temp_v1 = arg0->unk3C;
    if (temp_v1 != 0) {
        func_004A45D0(temp_v1);
    }
    func_004F4500(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
