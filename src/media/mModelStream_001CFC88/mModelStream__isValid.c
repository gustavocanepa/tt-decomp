#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct mModelStream__virtual_18_arg0 {
    char pad0[0x28];
    s32 unk28;
};

s32 mModelStream__isValid(struct mModelStream__virtual_18_arg0 *arg0) {
    return arg0->unk28 != 0;
}
