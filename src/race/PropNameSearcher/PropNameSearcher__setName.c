#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 pdiRiderman__Skeleton__getBoneIndex(s32);                             /* extern */

struct PropNameSearcher__virtual_00_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void PropNameSearcher__setName(struct PropNameSearcher__virtual_00_arg0 *arg0, s32 arg1) {
    if ((arg1 != 0) && (arg0->unk4 == 0) && (pdiRiderman__Skeleton__getBoneIndex(arg1) < 0)) {
        arg0->unk4 = arg1;
    }
}
