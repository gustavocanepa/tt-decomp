#include "types.h"
extern s32 (*D_00585D00)(void);
s32 func_00417038(void) {
    if (D_00585D00 == 0) return 0;
    return D_00585D00();
}
