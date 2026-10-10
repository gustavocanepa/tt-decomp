#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_001321D0();                                /* extern */

struct func_00518488_arg0 {
    char pad0[0x17C];
    s32 unk17C;
};

f32 func_00518488(struct func_00518488_arg0 *arg0) {
    return (f32) arg0->unk17C / func_001321D0();
}
