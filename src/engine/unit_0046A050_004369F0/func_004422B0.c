#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00447D00(s32, s32);
typedef struct { s32 a; f32 b; } T;
T *func_004422B0(T *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 f;
    func_00447D00(arg3, arg2);
    f = 1000000.0f;
    arg0->a = 6;
    arg0->b = f;
    return arg0;
}
