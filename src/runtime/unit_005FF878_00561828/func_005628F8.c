#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005628F8_arg0 {
    char pad0[0x10F0];
    s32 unk10F0;
};

void func_005628F8(struct func_005628F8_arg0 *arg0, s32 arg1) {
    arg0->unk10F0 = arg1;
}
