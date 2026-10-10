#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004473A8(s32);                         /* extern */

struct func_0043C3C8_arg0 {
    s32 unk0;
    char pad4[0x18];
    f32 unk1C;
};

void func_0043C3C8(struct func_0043C3C8_arg0 *arg0) {
    func_004473A8(arg0->unk0);
    arg0->unk1C = 1.0f;
}
