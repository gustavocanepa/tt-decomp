#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0047EE88(s32);                         /* extern */

struct func_0047F8D8_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_0047F8D8(struct func_0047F8D8_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 != 0) {
        func_0047EE88(temp_v0);
        arg0->unk4 = 0;
    }
}
