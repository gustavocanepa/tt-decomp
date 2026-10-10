#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043A180();                            /* extern */

struct func_004399A8_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_004399A8(struct func_004399A8_arg0 *arg0) {
    if (arg0->unk14 == 0) {
        func_0043A180();
    }
}
