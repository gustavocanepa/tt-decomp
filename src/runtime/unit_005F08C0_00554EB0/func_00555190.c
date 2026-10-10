#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00555190_arg0 {
    char pad0[0x3574];
    s32 unk3574;
};

void func_00555190(struct func_00555190_arg0 *arg0, s32 arg1) {
    arg0->unk3574 = arg1;
}
