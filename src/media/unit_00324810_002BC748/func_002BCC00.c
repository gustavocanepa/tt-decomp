#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */

struct func_002BCC00_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_002BCC00(struct func_002BCC00_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk8;
    if (temp_v0 != 0) {
        func_004A45D0(temp_v0);
    }
    arg0->unk8 = 0;
}
