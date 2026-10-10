/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F42C8(s32);                         /* extern */

struct func_004B6148_arg0 {
    char pad0[0x3C];
    s32 unk3C;
    s32 unk40;
};

void func_004B6148(struct func_004B6148_arg0 *arg0) {
    if (arg0->unk3C != 0) {
        arg0->unk3C = 0;
        func_004F42C8(arg0->unk40);
    }
}
