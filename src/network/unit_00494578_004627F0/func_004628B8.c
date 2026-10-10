#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00462CA0();                            /* extern */

struct func_004628B8_arg0 {
    char pad0[0x964];
    s32 unk964;
};

void func_004628B8(struct func_004628B8_arg0 *arg0, s32 arg1) {
    if (arg0->unk964 != arg1) {
        func_00462CA0();
        arg0->unk964 = arg1;
    }
}
