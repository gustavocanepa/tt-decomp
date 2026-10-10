#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001DBFD8();                            /* extern */

extern char D_005AEDB0[];
struct func_00524968_arg0 {
    char pad0[0x18];
    s32 unk18;
};

void func_00524968(struct func_00524968_arg0 *arg0) {
    func_001DBFD8();
    arg0->unk18 = (s32)D_005AEDB0;
}
