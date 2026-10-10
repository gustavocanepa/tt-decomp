#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C5188();                            /* extern */
s32 func_004C67F8(s32);                         /* extern */
s32 func_004C6A38(void *);                      /* extern */

extern char D_005DB250[];
struct func_004C5D98_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void func_004C5D98(void *arg0) {
    func_004C5188();
    ((struct func_004C5D98_arg0 *)arg0)->unk64 = (s32)D_005DB250;
    func_004C67F8(arg0 + 0x234);
    func_004C6A38(arg0 + 0x24C);
}
