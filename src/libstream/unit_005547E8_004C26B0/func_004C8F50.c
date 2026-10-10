#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004C8F50_arg0 {
    char pad0[0x2FE8];
    s32 unk2FE8;
};

void func_004C8F50(struct func_004C8F50_arg0 *arg0, s32 arg1) {
    arg0->unk2FE8 = arg1;
}
