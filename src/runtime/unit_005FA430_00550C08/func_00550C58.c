#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550C58_arg0 {
    char pad0[0x327B0];
    s32 unk327B0;
};

void func_00550C58(struct func_00550C58_arg0 *arg0, s32 arg1) {
    arg0->unk327B0 = arg1;
}
