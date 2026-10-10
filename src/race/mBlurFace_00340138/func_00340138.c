#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00554B88();                            /* extern */

struct func_00340138_arg0 {
    char pad0[0xD8];
    s32 unkD8;
    s32 unkDC;
};

void func_00340138(struct func_00340138_arg0 *arg0) {
    func_00554B88();
    arg0->unkD8 = 0;
    arg0->unkDC = 0;
}
