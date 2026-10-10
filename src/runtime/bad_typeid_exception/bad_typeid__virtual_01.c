#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 *exception__structor_3();                               /* extern */

s32 bad_typeid__virtual_01(void **arg0) {
    s32 *var_v0;

    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(*arg0, s32 *(**)(), 4)();
    } else {
        var_v0 = exception__structor_3();
    }
    return *var_v0;
}
