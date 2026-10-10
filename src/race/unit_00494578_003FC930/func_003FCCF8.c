#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003FCCF8_arg0 {
    char pad0[0x1718];
    s32 unk1718;
};

s32 func_003FCCF8(struct func_003FCCF8_arg0 *arg0) {
    return arg0->unk1718 == 0;
}
