#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00541868_arg0 {
    char pad0[0x154];
    s32 unk154;
};

void func_00541868(struct func_00541868_arg0 *arg0, s32 arg1) {
    arg0->unk154 = arg1;
}
