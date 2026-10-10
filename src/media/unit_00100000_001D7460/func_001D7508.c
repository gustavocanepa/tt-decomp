#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D7508_arg0 {
    char pad0[0x1DC];
    s32 unk1DC;
};

void func_001D7508(struct func_001D7508_arg0 *arg0, s32 arg1) {
    arg0->unk1DC = arg1;
}
