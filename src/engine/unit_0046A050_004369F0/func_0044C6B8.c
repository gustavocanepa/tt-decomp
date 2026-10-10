#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D9F98[];
struct func_0044C6B8_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

void func_0044C6B8(struct func_0044C6B8_arg0 *arg0, s32 arg1) {
    arg0->unk3C = (s32)D_005D9F98;
    func_004AE9F0(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
