#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001AF820();                            /* extern */
s32 func_003EEC90(void *);                      /* extern */

extern char D_005ADB10[];
struct func_001AFF80_arg0 {
    char pad0[0x5C];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
};

void func_001AFF80(void *arg0) {
    func_001AF820();
    ((struct func_001AFF80_arg0 *)arg0)->unk60 = 0;
    ((struct func_001AFF80_arg0 *)arg0)->unk64 = 0;
    ((struct func_001AFF80_arg0 *)arg0)->unk5C = (s32)D_005ADB10;
    ((struct func_001AFF80_arg0 *)arg0)->unk68 = 0;
    ((struct func_001AFF80_arg0 *)arg0)->unk6C = 0;
    func_003EEC90(arg0 + 0x70);
}
