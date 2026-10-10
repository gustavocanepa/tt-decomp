/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004CE8D8(void *);                      /* extern */
s32 func_004F42C8(s32);                         /* extern */
s32 func_004F4348(s32);                         /* extern */

struct func_004CEB90_arg0 {
    char pad0[0x48];
    s32 unk48;
    char pad4C[0x10];
    s32 unk5C;
};

void func_004CEB90(struct func_004CEB90_arg0 *arg0, s32 arg1) {
    func_004F4348(arg0->unk5C);
    arg0->unk48 = arg1;
    func_004CE8D8(arg0);
    func_004F42C8(arg0->unk5C);
}
