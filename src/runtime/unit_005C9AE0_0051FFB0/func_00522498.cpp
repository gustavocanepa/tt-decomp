#include "types.h"

extern "C" void **func_001AF2E0(void *, int);

extern "C" f32 func_00522498(void *arg0) {
    return *(f32 *)*(void ***)func_001AF2E0(arg0, 1);
}
