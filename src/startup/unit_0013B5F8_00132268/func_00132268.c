#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00132268_arg0 {
    char pad0[0x17C];
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
    s32 unk18C;
    s32 unk190;
};

void func_00132268(struct func_00132268_arg0 *arg0) {
    arg0->unk17C = 0;
    arg0->unk188 = -1;
    arg0->unk180 = 0;
    arg0->unk184 = 0;
    arg0->unk18C = 0;
    arg0->unk190 = 0;
}
