#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_00405D88_arg0 {
    char pad0[0x4D8];
    s32 unk4D8;
};

void func_00405D88(void *arg0, s8 arg1) {
    M2C_FIELD(((((struct func_00405D88_arg0 *)arg0)->unk4D8 * 0x190) + arg0), s8 *, 0x14A) = arg1;
}
