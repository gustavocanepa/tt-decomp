/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

static inline u32 write_ring(u8 *arg0, u8 *arg1, u32 arg2, u32 capacity) {
    u32 temp_a4;
    u32 temp_a5;
    u32 temp_a5_2;
    u32 var_a3;
    u32 var_a4;
    u32 var_a4_2;
    u32 var_a6;
    u8 *var_a1;
    u8 *var_a2;
    u8 temp_v1;
    u8 temp_v1_2;

    var_a1 = arg1;
    temp_a5_2 = capacity - M2C_FIELD(arg0, s32 *, 8);
    temp_a5 = (arg2 < temp_a5_2) ? arg2 : temp_a5_2;
    if (temp_a5 != 0) {
        temp_a4 = M2C_FIELD(arg0, u32 *, 0);
        var_a3 = temp_a5;
        var_a6 = temp_a4 + temp_a5;
        var_a2 = arg0 + temp_a4 + 0xC;
        if (var_a6 > capacity) {
            var_a3 = capacity - temp_a4;
            var_a4 = 0;
            if (var_a3 != 0) {
                do {
                    temp_v1 = *var_a1;
                    var_a1 += 1;
                    var_a4 += 1;
                    *var_a2 = temp_v1;
                    var_a2 += 1;
                } while (var_a4 < var_a3);
            }
            var_a6 -= capacity;
            var_a2 = arg0 + 0xC;
            var_a3 = var_a6;
        }
        var_a4_2 = 0;
        if (var_a3 != 0) {
            do {
                temp_v1_2 = *var_a1;
                var_a1 += 1;
                var_a4_2 += 1;
                *var_a2 = temp_v1_2;
                var_a2 += 1;
            } while (var_a4_2 < var_a3);
        }
        M2C_FIELD(arg0, u32 *, 0) = var_a6;
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + temp_a5);
    }
    return temp_a5;
}

extern "C" u32 func_00543850(u8 *p,u8 *s,u32 n) { return write_ring(p,s,n,256); }
