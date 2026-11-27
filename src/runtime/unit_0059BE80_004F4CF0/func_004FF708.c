/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004F6678(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

extern char D_0078F428[];
extern char D_005A315C[];
s32 func_004FF708(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, M2C_UNK arg4, M2C_UNK arg5, M2C_UNK arg6) {
    *(s32 *)D_005A315C = 0;
    func_004F6678((s32)D_0078F428, 0, 4);
    return 0;
}
