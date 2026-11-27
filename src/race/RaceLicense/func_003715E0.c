/* compiler: ee-gcc2.96-nosched1 */
#include "types.h"
#define NULL 0
#include "m2c_macros.h"

void func_003715E0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x104A0) = arg1;
    M2C_FIELD(arg0, s32 *, 0x3A944) = arg1;
    M2C_FIELD(arg0, s32 *, 0x3A948) = 0;
}
