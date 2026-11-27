#include "types.h"

extern s32 D_00598334;
extern s32 D_0077413C;
extern "C" void func_004F4348(s32);
extern "C" void func_004F42C8(s32);

extern "C" s32 func_004B6470(void) {
    s32 *lock = &D_00598334;
    s32 r;
    func_004F4348(*lock);
    r = D_0077413C;
    func_004F42C8(*lock);
    return r;
}
