#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00426FA8_arg0 {
    char pad0[0x448];
    s32 unk448;
};

s32 func_00426FA8(struct func_00426FA8_arg0 *arg0) {
    return arg0->unk448;
}
