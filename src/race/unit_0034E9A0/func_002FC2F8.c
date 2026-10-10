#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002FC2F8_arg0 {
    char pad0[0x23960];
    s32 unk23960;
};

u32 func_002FC2F8(struct func_002FC2F8_arg0 *arg0, s32 arg1) {
    return (u32) (arg0->unk23960 + arg1) / 3U;
}
