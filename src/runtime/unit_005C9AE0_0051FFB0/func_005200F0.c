#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001986F8(s32);                         /* extern */

struct func_005200F0_arg0 {
    char pad0[0x50];
    s32 unk50;
};

s32 func_005200F0(struct func_005200F0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk50;
    if (temp_v0 != 0) {
        func_001986F8(temp_v0);
    }
}
