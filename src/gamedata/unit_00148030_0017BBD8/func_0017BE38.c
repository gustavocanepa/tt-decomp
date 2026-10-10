#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104838(void *);                      /* extern */
s32 func_001BE348();                            /* extern */

extern char D_005A92E0[];
extern char D_005A9580[];
struct func_0017BE38_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
};

void func_0017BE38(void *arg0) {
    func_001BE348();
    ((struct func_0017BE38_arg0 *)arg0)->unk4 = (s32)D_005A92E0;
    ((struct func_0017BE38_arg0 *)arg0)->unk2C = (s32)D_005A9580;
    func_00104838(arg0 + 0x7C);
}
