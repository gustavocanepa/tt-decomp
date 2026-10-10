#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 *func_00575BB0(s32 *arg0, s32 (*arg1)(s32)) {
    arg1(*arg0);
    return arg0;
}
