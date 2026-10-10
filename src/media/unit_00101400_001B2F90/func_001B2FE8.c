/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B2F90(void *);                      /* extern */
s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */

struct func_001B2FE8_arg0 {
    char pad0[0xDC];
    s32 unkDC;
};

void func_001B2FE8(void *arg0, s32 arg1) {
    s32 temp_s2;

    temp_s2 = arg0 + 0x8C;
    func_004A4D68(temp_s2);
    ((struct func_001B2FE8_arg0 *)arg0)->unkDC = arg1;
    if (arg1 != 0) {
        func_001B2F90(arg0);
    }
    func_004A4DD8(temp_s2);
}
