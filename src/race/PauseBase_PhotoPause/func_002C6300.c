/* compiler: ee-gcc2.96-nosched1 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00377F28();                            /* extern */

void func_002C6300(void *arg0) {
    func_00377F28();
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C4) = -1;
    M2C_FIELD(arg0, s32 *, 0x2B0) = -1;
    M2C_FIELD(arg0, s32 *, 0x2BC) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C0) = 0;
}
