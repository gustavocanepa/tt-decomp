#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00518D58_arg0 {
    char pad0[0x9C];
    s32 unk9C;
};

void func_00518D58(struct func_00518D58_arg0 *arg0, s32 arg1) {
    arg0->unk9C = arg1;
}
