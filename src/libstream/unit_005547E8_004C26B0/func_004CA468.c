#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9C0();                            /* extern */
s32 func_00574BE8(void *);                      /* extern */

extern char D_005DB2E8[];
struct func_004CA468_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

void func_004CA468(void *arg0) {
    ((struct func_004CA468_arg0 *)arg0)->unk3C = (s32)D_005DB2E8;
    func_004AE9C0();
    func_00574BE8(arg0 + 0x30);
}
