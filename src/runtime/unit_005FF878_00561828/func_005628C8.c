#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005628C8_arg0 {
    char pad0[0x10E4];
    s32 unk10E4;
};

void func_005628C8(struct func_005628C8_arg0 *arg0, s32 arg1) {
    arg0->unk10E4 = arg1;
}
