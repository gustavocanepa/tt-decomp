#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002571D8();                                /* extern */

struct func_002541E8_arg0 {
    char pad0[0x144];
    s32 unk144;
};

s32 func_002541E8(struct func_002541E8_arg0 *arg0) {
    return func_002571D8() + (arg0->unk144 != 0);
}
