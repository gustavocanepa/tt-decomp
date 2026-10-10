#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551320_arg0 {
    char pad0[0xD014];
    s32 unkD014;
};

void func_00551320(struct func_00551320_arg0 *arg0, s32 arg1) {
    arg0->unkD014 = arg1;
}
