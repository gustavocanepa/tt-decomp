#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" M2C_UNK func_00131D90(s32, s32, s32, s32);          /* extern */
extern "C" f32 func_00132208();                                /* extern */
extern "C" f32 func_00439550(M2C_UNK, f32);                    /* extern */

extern char D_005865D0[];
extern "C" void func_00131ED0(s32 arg0, s32 arg1, s32 arg2) {
    func_00131D90((s32)(arg0), (s32)(arg1), (s32)(arg2), (s32)((s32) ((func_00439550((M2C_UNK)((s32)D_005865D0), (f32)(func_00132208())) * 0x1.9000000000000p+6f) + 0x1.0000000000000p-1f)));
}
