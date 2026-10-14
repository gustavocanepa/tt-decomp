/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef signed char s8; typedef unsigned char u8;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern "C" void func_002C5F28(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, s8 arg6) {
    volatile s8 sp0;
    s32 stride=arg1*arg2;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_v0_2;
    s32 var_t0;
    s32 var_t1;
    s32 var_t3;
    s32 var_v1;
    s32 var_v1_2;
    u8 *var_a6;
    u8 *var_a6_2;
    u8 *var_a7;
    u8 *var_a7_2;
    u8 *base;
    u8 temp_v0;
    u8 temp_v0_3;

    sp0 = arg6;
    if (arg1 < arg4) arg4=arg1;

    var_t3 = 0;
    if (arg1 > 0) {
        do {
            temp_t2 = arg1 - var_t3;
            base = M2C_FIELD(arg5, u8 **, 4);
            temp_t2_2 = (arg4 < temp_t2) ? arg4 : temp_t2;
            var_a7 = base;
            if (arg2 > 0) {
                var_t1 = var_t3;
                var_t0 = arg2;
                do {
                    var_a6 = arg0 + var_t1;
                    if (arg3 > 0) {
                        var_v1 = arg3;
                        do {
                            temp_v0 = *var_a6;
                            var_a6 += stride;
                            var_v1 -= 1;
                            *var_a7 = temp_v0;
                            var_a7 += temp_t2_2;
                        } while (var_v1 != 0);
                    }
                    var_t0 -= 1;
                    var_t1 += arg1;
                } while (var_t0 != 0);
                base=M2C_FIELD(arg5,u8 **,4);
            }
            temp_v0_2 = arg2 * arg3;
            var_a7_2 = base;
            var_a6_2 = arg0 + var_t3;
            if (temp_v0_2 > 0) {
                var_v1_2 = temp_v0_2;
                do {
                    temp_v0_3 = *var_a7_2;
                    var_a7_2 += temp_t2_2;
                    var_v1_2 -= 1;
                    *var_a6_2 = temp_v0_3;
                    var_a6_2 += arg1;
                } while (var_v1_2 != 0);
            }
            var_t3 += arg4;
        } while (var_t3 < arg1);
    }
}
