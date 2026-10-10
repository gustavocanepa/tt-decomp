#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00417370(s32);                             /* extern */

/* A member array indexed by a variable: base + index (a struct field), not index + base. */
#define M2C_ARRAY(base, T, off, idx) (((struct { char pad[off]; T a[1]; } *)(base))->a[idx])
struct func_00417470_arg1 {
    s32 unk0;
    f32 unk4;
};

void func_00417470(s32 arg0, struct func_00417470_arg1 *arg1) {
    s32 temp_v0;

    temp_v0 = func_00417370(arg1->unk0);
    if (temp_v0 >= 0) {
        M2C_ARRAY(arg0, f32, 4, temp_v0) = (f32) arg1->unk4;
    }
}
