#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0042DC98(s32);                         /* extern */

s32 func_0042BD98(s32 arg0) {
    s32 var_v1;

    var_v1 = -1;
    switch (arg0) {                                 /* irregular */
    case 0:
        var_v1 = 0;
        break;
    case 1:
        var_v1 = 1;
        break;
    case 2:
        var_v1 = 2;
        break;
    }
    if (var_v1 != -1) {
        func_0042DC98(var_v1);
    }
}
