#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A7988_arg0 {
    char pad0[0x34];
    f32 unk34;
    char pad38[0x34];
    f32 unk6C;
    char pad70[0x14];
    s32 unk84;
};

f32 func_003A7988(struct func_003A7988_arg0 *arg0) {
    if (arg0->unk84 < 2) {
        return arg0->unk34;
    }
    return arg0->unk6C;
}
