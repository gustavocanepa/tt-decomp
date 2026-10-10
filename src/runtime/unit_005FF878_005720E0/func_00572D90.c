#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F4348(s32);                         /* extern */

struct func_00572D90_arg0 {
    char pad0[0x40];
    s32 unk40;
    char pad44[0x7C];
    s32 unkC0;
};

s32 func_00572D90(struct func_00572D90_arg0 *arg0) {
    func_004F4348(arg0->unk40);
    return arg0->unkC0 == 0;
}
