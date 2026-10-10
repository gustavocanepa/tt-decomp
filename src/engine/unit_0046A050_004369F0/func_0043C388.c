#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00447398(s32);                         /* extern */

struct func_0043C388_arg0 {
    s32 unk0;
    char pad4[0x18];
    f32 unk1C;
};

void func_0043C388(struct func_0043C388_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    if (temp_v0 != 0) {
        func_00447398(temp_v0);
        arg0->unk1C = 1.0f;
    }
}
