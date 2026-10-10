#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 mAnchorActor__structor_0();                            /* extern */

extern char D_005D7680[];
struct func_003EE100_arg0 {
    char pad0[0x8E8];
    s32 unk8E8;
    char pad8EC[0x1C];
    s32 unk908;
    s32 unk90C;
};

void func_003EE100(struct func_003EE100_arg0 *arg0) {
    mAnchorActor__structor_0();
    arg0->unk90C = 0;
    arg0->unk908 = 0;
    arg0->unk8E8 = (s32)D_005D7680;
}
