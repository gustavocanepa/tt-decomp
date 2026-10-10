#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00402218_arg0 {
    char pad0[0x23F88];
    s32 unk23F88;
};

void func_00402218(struct func_00402218_arg0 *arg0, s32 arg1) {
    arg0->unk23F88 = arg1;
}
