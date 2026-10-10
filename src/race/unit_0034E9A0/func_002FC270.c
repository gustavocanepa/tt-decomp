#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002FC270_arg0 {
    char pad0[0x23964];
    u32 unk23964;
};

u32 func_002FC270(struct func_002FC270_arg0 *arg0) {
    return (u32) arg0->unk23964 / 3U;
}
