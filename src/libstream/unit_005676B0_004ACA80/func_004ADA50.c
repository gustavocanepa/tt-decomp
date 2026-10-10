#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AD9E0(void *);                      /* extern */
s32 func_004ADE50(void *);                      /* extern */

extern char D_005DAE30[];
struct func_004ADA50_arg0 {
    char pad0[0x54];
    s32 unk54;
};

void func_004ADA50(void *arg0) {
    ((struct func_004ADA50_arg0 *)arg0)->unk54 = (s32)D_005DAE30;
    func_004AD9E0(arg0 + 0x4C);
    func_004ADE50(arg0);
}
