#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00520818_arg0 {
    char pad0[0x4A];
    s16 unk4A;
};

void func_00520818(struct func_00520818_arg0 *arg0, s16 arg1) {
    arg0->unk4A = arg1;
}
