#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s16, u8);                         /* extern */

struct func_003825F8_arg0 {
    char pad0[0x10];
    s16 unk10;
    char pad12[0xC];
    u8 unk1E;
};

f32 func_003825F8(struct func_003825F8_arg0 *arg0) {
    return func_00381890(arg0->unk10, arg0->unk1E) * 0x1.47ae140000000p-7f;
}
