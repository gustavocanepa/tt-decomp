#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00571EA0_arg1 {
    u8 unk0;
    u8 unk1;
};

s32 func_00571EA0(s32 arg0, struct func_00571EA0_arg1 *arg1) {
    return (arg1->unk1 << 8) | arg1->unk0;
}
