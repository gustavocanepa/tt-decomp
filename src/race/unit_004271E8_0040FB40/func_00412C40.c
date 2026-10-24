#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_00585C90[];
s32 func_00412C40(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, M2C_UNK arg4, M2C_UNK arg5, M2C_UNK arg6) {
    return M2C_FIELD(**(void ***)D_00585C90, s32 *, 8);
}
