#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005628E8_arg0 {
    char pad0[0x10EC];
    s32 unk10EC;
};

void func_005628E8(struct func_005628E8_arg0 *arg0, s32 arg1) {
    arg0->unk10EC = arg1;
}
