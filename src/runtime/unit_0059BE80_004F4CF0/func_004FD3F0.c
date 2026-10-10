#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004FD3F0_arg1 {
    char pad0[0x8];
    s32 unk8;
};
struct func_004FD3F0_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_004FD3F0(struct func_004FD3F0_arg0 *arg0, struct func_004FD3F0_arg1 *arg1) {
    arg1->unk8 = (s32) arg0->unk10;
}
