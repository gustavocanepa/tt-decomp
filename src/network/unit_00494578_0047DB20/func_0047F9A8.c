#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B08B8();                            /* extern */

extern char D_005DA7F0[];
struct func_0047F9A8_arg0 {
    char pad0[0x30];
    s32 unk30;
};

void func_0047F9A8(struct func_0047F9A8_arg0 *arg0) {
    func_004B08B8();
    arg0->unk30 = (s32)D_005DA7F0;
}
