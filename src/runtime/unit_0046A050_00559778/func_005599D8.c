#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005599D8_arg0 {
    char pad0[0x1172];
    s8 unk1172;
};

s32 func_005599D8(struct func_005599D8_arg0 *arg0) {
    return arg0->unk1172 != 0;
}
