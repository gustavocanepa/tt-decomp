#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002F9A40();                                /* extern */

struct func_002F9B08_arg0 {
    char pad0[0x7E9];
    s8 unk7E9;
};

void func_002F9B08(struct func_002F9B08_arg0 *arg0) {
    if (func_002F9A40() != 0) {
        arg0->unk7E9 = 0;
    }
}
