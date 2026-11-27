#include "types.h"

f32 func_002F6D00(f32 *arg0, f32 fparg0) {
    f32 var_f1;
    f32 var_f2 = 1.0f;

    if (fparg0 < -0x1.921FB4p+0f) {
        var_f1 = fparg0 + 0x1.921FB4p+1f;
    } else if (fparg0 < 0.0f) {
        var_f2 = -1.0f;
        var_f1 = -fparg0;
    } else if (fparg0 < 0x1.921FB4p+0f) {
        var_f1 = fparg0;
    } else {
        var_f2 = -1.0f;
        var_f1 = 0x1.921FB4p+1f - fparg0;
    }
    *arg0 = var_f2;
    return var_f1;
}
