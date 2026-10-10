#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0020C258();                            /* extern */
s32 mScrollWindow__onHPinchMotion(s32, s32, s32);                   /* extern */
s32 func_00276FE8(s32, s32, s32);                   /* extern */

struct func_002758D8_arg0 {
    char pad0[0xD4];
    s32 unkD4;
    s32 unkD8;
};

s32 func_002758D8(struct func_002758D8_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;

    func_0020C258();
    temp_a0 = arg0->unkD4;
    if (temp_a0 != 0) {
        if (arg0->unkD8 != 0) {
            return mScrollWindow__onHPinchMotion(temp_a0, arg1, arg2);
        }
        return func_00276FE8(temp_a0, arg1, arg2);
    }
    return 0;
}
