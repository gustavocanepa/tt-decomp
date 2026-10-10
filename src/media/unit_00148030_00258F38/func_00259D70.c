#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00259D70_arg0 {
    char pad0[0xDC];
    s32 unkDC;
};

void func_00259D70(struct func_00259D70_arg0 *arg0, s32 arg1) {
    arg0->unkDC = arg1;
    if (arg1 <= 0) {
        arg0->unkDC = 1;
    }
}
