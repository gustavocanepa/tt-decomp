#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001D7DA0();                            /* extern */
s32 func_001DBFD8(void *, void *);              /* extern */

extern char D_005B0BB0[];
extern char D_005B0E40[];
struct func_001DB450_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
};

void func_001DB450(void *arg0) {
    func_001D7DA0();
    ((struct func_001DB450_arg0 *)arg0)->unk4 = (s32)D_005B0BB0;
    ((struct func_001DB450_arg0 *)arg0)->unk2C = (s32)D_005B0E40;
    func_001DBFD8(arg0 + 0x4C, arg0);
}
