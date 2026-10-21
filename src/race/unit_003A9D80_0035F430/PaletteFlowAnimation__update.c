#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void PaletteFlowAnimation__update(void *arg0, f32 fparg0) {
    f32 temp_f1;

    temp_f1 = M2C_FIELD(arg0, f32 *, 8) + (M2C_FIELD(arg0, f32 *, 4) * fparg0);
    M2C_FIELD(arg0, f32 *, 8) = (f32) (temp_f1 - (f32) (s32) temp_f1);
}
