#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002E7BE0(void *);                      /* extern */
s32 func_004B2C68();                            /* extern */

extern char D_005C9288[];
struct func_002E7AA0_arg0 {
    char pad0[0x48];
    s32 unk48;
    s32 unk4C;
    s32 unk50;
};

void func_002E7AA0(struct func_002E7AA0_arg0 *arg0) {
    arg0->unk50 = (s32)D_005C9288;
    func_004B2C68();
    arg0->unk48 = 0;
    arg0->unk4C = 0;
    func_002E7BE0(arg0);
}
