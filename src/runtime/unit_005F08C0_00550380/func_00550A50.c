#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550A50_arg0 {
    char pad0[0x447A4];
    s32 unk447A4;
};

void func_00550A50(struct func_00550A50_arg0 *arg0, s32 arg1) {
    arg0->unk447A4 = arg1;
}
