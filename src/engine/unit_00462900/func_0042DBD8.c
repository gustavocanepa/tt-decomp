#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004C4588(s32);                         /* extern */

struct func_0042DBD8_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_0042DBD8(struct func_0042DBD8_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk20;
    if (temp_v0 != 0) {
        func_004C4588(temp_v0);
        arg0->unk20 = 0;
    }
}
