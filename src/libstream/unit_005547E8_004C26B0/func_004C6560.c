/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004C6480(M2C_UNK, M2C_UNK, s32, void *);                 /* extern */

void func_004C6560(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    void *temp_a3;

    temp_a3 = arg2 + (arg3 * 4);
    func_004C6480(arg0, arg1, arg2 + M2C_FIELD(temp_a3, s32 *, 8), temp_a3);
}
