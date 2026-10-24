#include "types.h"
f32 func_003151F0(f32);
void func_00315338(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 temp_f1;
    fparg1 = func_003151F0(fparg1);
    fparg3 = func_003151F0(fparg3);
    temp_f1 = fparg1 - fparg3;
    if (temp_f1 >= 0x1.921fb40000000p+1f) {
        fparg3 += 0x1.921fb40000000p+2f;
    } else if (temp_f1 < -0x1.921fb40000000p+1f) {
        fparg1 += 0x1.921fb40000000p+2f;
    }
    func_003151F0((fparg0 * fparg1) + (fparg2 * fparg3));
}
