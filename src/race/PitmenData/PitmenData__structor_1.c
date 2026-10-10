#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003799F0();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D3B30[];
struct PitmenData__structor_1_arg0 {
    char pad0[0x6C];
    s32 unk6C;
};

void PitmenData__structor_1(struct PitmenData__structor_1_arg0 *arg0, s32 arg1) {
    arg0->unk6C = (s32)D_005D3B30;
    func_003799F0();
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
