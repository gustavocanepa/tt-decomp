#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550C48_arg0 {
    char pad0[0x32798];
    s32 unk32798;
};

void func_00550C48(struct func_00550C48_arg0 *arg0, s32 arg1) {
    arg0->unk32798 = arg1;
}
