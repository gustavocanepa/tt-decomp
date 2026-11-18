#include "types.h"

struct S_00249FF0;

extern "C" void func_001E9718(struct S_00249FF0 *arg0, s32 arg1);
extern "C" struct S_00249FF0 *func_00210118(void);

extern "C" void func_001FA1E0(void) {
    struct S_00249FF0 *temp_v0 = func_00210118();

    if (temp_v0 != 0) {
        func_001E9718(temp_v0, 0);
    }
}
