#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005629C8_arg0 {
    char pad0[0x1124];
    s32 unk1124;
};

void func_005629C8(struct func_005629C8_arg0 *arg0, s32 arg1) {
    arg0->unk1124 = arg1;
}
