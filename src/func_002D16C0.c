/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00104AC0(s32, s32, s32, s32, s32);     /* extern */

void func_002D16C0(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0xE3B4) != 0) {
        func_00104AC0(arg1, (s32) M2C_FIELD(arg0, f32 *, 0xE3A4), (s32) M2C_FIELD(arg0, f32 *, 0xE3A8), (s32) M2C_FIELD(arg0, f32 *, 0xE3AC), (s32) M2C_FIELD(arg0, f32 *, 0xE3B0));
    }
}
