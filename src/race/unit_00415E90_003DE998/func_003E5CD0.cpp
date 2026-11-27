#include "types.h"

extern "C" f32 *func_003E5C78(f32 *arg0, f32 fparg0);

extern "C" f32 *func_003E5CD0(f32 *arg0, f32 *arg1) {
    return func_003E5C78(arg0, *arg1);
}
