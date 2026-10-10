#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B35F8();                            /* extern */
s32 func_001DBFD8(void *, void *);              /* extern */

extern char D_005B7378[];
extern char D_005B7630[];
struct func_00229B10_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
    char pad30[0x38];
    s32 unk68;
};

void func_00229B10(void *arg0) {
    func_001B35F8();
    ((struct func_00229B10_arg0 *)arg0)->unk4 = (s32)D_005B7378;
    ((struct func_00229B10_arg0 *)arg0)->unk2C = (s32)D_005B7630;
    func_001DBFD8(arg0 + 0x4C, arg0);
    ((struct func_00229B10_arg0 *)arg0)->unk68 = 0;
}
