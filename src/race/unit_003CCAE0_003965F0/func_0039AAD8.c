/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_002F04D8(s32);                         /* extern */
s32 func_0039AB40(s32, s32, s32, s32);          /* extern */

void func_0039AAD8(s32 arg0, s32 arg1, s32 arg2) {
    func_002F04D8(arg2);
    func_0039AB40(arg0, arg1, M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0x969C), arg2);
}
