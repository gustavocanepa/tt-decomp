#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */

struct func_003C7A00_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_003C7A00(struct func_003C7A00_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 != 0) {
        func_004A45D0(temp_v0);
        arg0->unk4 = 0;
    }
}
