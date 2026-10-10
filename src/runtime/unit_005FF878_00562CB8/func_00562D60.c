#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562D60_arg0 {
    char pad0[0x1168];
    s32 unk1168;
};

void func_00562D60(struct func_00562D60_arg0 *arg0, s32 arg1) {
    arg0->unk1168 = arg1;
}
