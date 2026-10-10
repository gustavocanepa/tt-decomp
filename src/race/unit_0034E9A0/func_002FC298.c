#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002FC298_arg0 {
    char pad0[0x23960];
    u32 unk23960;
};

u32 func_002FC298(struct func_002FC298_arg0 *arg0) {
    return (u32) arg0->unk23960 / 3U;
}
