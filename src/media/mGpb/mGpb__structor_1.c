#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0023E578(void *, s32);                 /* extern */
s32 func_002A7618();                            /* extern */
s32 func_0045D898(s32);                         /* extern */

extern char D_005B9C30[];
struct mGpb__structor_1_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void mGpb__structor_1(void *arg0, s32 arg1) {
    func_002A7618();
    ((struct mGpb__structor_1_arg0 *)arg0)->unk4 = (s32)D_005B9C30;
    func_0045D898(arg0 + 0x10);
    func_0023E578(arg0, arg1);
}
