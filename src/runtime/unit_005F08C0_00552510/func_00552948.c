#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552948_arg0 {
    char pad0[0x23968];
    s32 unk23968;
};

void func_00552948(struct func_00552948_arg0 *arg0, s32 arg1) {
    arg0->unk23968 = arg1;
}
