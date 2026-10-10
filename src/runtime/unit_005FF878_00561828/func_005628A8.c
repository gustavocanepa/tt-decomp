#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005628A8_arg0 {
    char pad0[0x10DC];
    s32 unk10DC;
};

void func_005628A8(struct func_005628A8_arg0 *arg0, s32 arg1) {
    arg0->unk10DC = arg1;
}
