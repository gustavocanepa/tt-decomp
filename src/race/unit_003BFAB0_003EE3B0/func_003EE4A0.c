#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00455B20();                            /* extern */

extern char D_005D75A0[];
struct func_003EE4A0_arg0 {
    char pad0[0x24];
    s32 unk24;
};

void func_003EE4A0(struct func_003EE4A0_arg0 *arg0) {
    func_00455B20();
    arg0->unk24 = (s32)D_005D75A0;
}
