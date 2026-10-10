#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004CBE80(s32, s32, s32);               /* extern */
s32 func_004CDC80(s32);                             /* extern */
s32 func_004CDD08(s32);                         /* extern */

struct func_004BD7F8_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x10];
    s32 unk20;
};

s32 func_004BD7F8(struct func_004BD7F8_arg0 *arg0, s32 arg1) {
    func_004CBE80(func_004CDC80(arg0->unkC), arg1, arg0->unk20);
    func_004CDD08(arg0->unkC);
    return 0;
}
