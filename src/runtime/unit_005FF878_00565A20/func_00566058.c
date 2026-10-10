#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050EC78(s32, s32);                    /* extern */

struct func_00566058_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_00566058(struct func_00566058_arg0 *arg0, s32 arg1) {
    func_0050EC78(arg0->unk14, arg1 * 8);
}
