#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004AEC10_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_004AEC10(struct func_004AEC10_arg0 *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = 0;
}
