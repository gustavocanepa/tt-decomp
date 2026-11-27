#include "types.h"

extern "C" f32 func_004B28D8();

extern "C" f32 func_004B2930(f32 fparg0, f32 fparg1) {
    return ((fparg1 - fparg0) * func_004B28D8()) + fparg0;
}
