#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_002571B8();                   /* extern */

struct func_00253F78_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

void func_00253F78(struct func_00253F78_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    if (arg0->unkD4 == 0) {
        M2C_FIELD(func_002571B8(), f32 *, 0xC) = fparg0;
        M2C_FIELD(func_002571B8(arg0, arg1), f32 *, 0x10) = fparg1;
        return;
    }
    M2C_FIELD(func_002571B8(), f32 *, 0xC) = fparg1;
    M2C_FIELD(func_002571B8(arg0, arg1), f32 *, 0x10) = fparg0;
}
