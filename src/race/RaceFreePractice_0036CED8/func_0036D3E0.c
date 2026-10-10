#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00385CC8();                            /* extern */

extern char D_005D1FF0[];
struct func_0036D3E0_arg0 {
    char pad0[0x134];
    s32 unk134;
};

void func_0036D3E0(struct func_0036D3E0_arg0 *arg0) {
    func_00385CC8();
    arg0->unk134 = (s32)D_005D1FF0;
}
