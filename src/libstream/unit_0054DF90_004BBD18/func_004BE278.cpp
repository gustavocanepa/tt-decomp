/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004CC168(s32);                         /* extern */
void func_004FA840(s32);                         /* extern */
s32 func_004FA860(s32);                         /* extern */
s32 func_005038D8(void);                         /* extern */
s32 func_00503928(void);                /* extern */

extern s32 D_00776D44, D_00776D48, D_00776D4C, D_00776D58, D_00776D5C;

s32 func_004BE278(void *arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_a5;
    s32 temp_a6;
    s32 temp_t1;
    s32 temp_t3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_s2;
    u32 var_s3;
    s32 var_s4;
    s32 var_t2;
    s32 var_v1;
    s32 var_v1_2;
    u32 temp_a4;
    u32 temp_s5;
    u32 var_a7;
    u32 var_s1;
    u32 var_t0;

    func_004FA860(M2C_FIELD(arg0, s32 *, 0x38));
    temp_s5 = M2C_FIELD(arg0, u32 *, 0x1C);
    temp_a3 = M2C_FIELD(arg0, s32 *, 0);
    temp_v1 = ((temp_s5 >> 8) & 0xF) + ((temp_s5 >> 0x10) & 3);
    temp_a6 = M2C_FIELD(arg0, s32 *, 0x24);
    var_s1 = temp_a3 - (temp_v1 * 0x10);
    s32 qwc = M2C_FIELD(arg0, s32 *, 8);
    var_s4 = M2C_FIELD(arg0, s32 *, 4);
    var_s3 = qwc + temp_v1;
    var_s2 = M2C_FIELD(arg0, s32 *, 0xC);
    if (var_s1 < (u32) (temp_a6 & 0x0FFFFFFF)) {
        s32 delta = temp_a6 - var_s1;
        s32 shift = D_00776D4C;
        var_s3 = (u32) delta >> 4;
        var_s4 = M2C_FIELD(arg0, s32 *, 0x28) & 0x0FFFFFFF;
        var_s1 += D_00776D58;
        if (temp_a3 == temp_a6 || temp_a3 == temp_a6 + (D_00776D44 << shift))
            var_t2 = 0;
        else
            var_t2 = 3;
        s32 distance = (D_00776D44 - M2C_FIELD(arg0, u32 *, 0x2C)) & D_00776D48;
        var_s2 = (var_s2 & 0x8FFFFFFF) | (var_t2 << 0x1C);
        var_v1 = 0;
        if ((distance < 0) || (distance >= M2C_FIELD(arg0, s32 *, 0x30))) {
            var_v1 = 1;
        }
        if (var_v1 != 0) {
            M2C_FIELD(arg0, u32 *, 0x2C) = (u32) (D_00776D44 - 1);
            M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + 1);
        }
    } else {
        temp_t3 = M2C_FIELD(arg0, s32 *, 0x28);
        if (temp_a3 != ((temp_t3 + (D_00776D44 * 0x10) + 0x10) & 0x0FFFFFFF)) {
            var_a7 = (u32) (temp_a3 - temp_a6) >> D_00776D4C;
        } else {
            var_a7 = 0;
        }
        if (var_s1 != ((temp_t3 + (D_00776D44 * 0x10) + 0x10) & 0x0FFFFFFF)) {
            var_t0 = (u32) (var_s1 - temp_a6) >> D_00776D4C;
        } else {
            var_t0 = 0;
        }
        if (var_a7 != var_t0) {
            temp_a4 = M2C_FIELD(arg0, u32 *, 0x2C);
            temp_t1 = M2C_FIELD(arg0, s32 *, 0x30);
            temp_a5 = D_00776D48;
            temp_a0 = D_00776D4C;
            if ((temp_a6 + ((temp_a3 - temp_a6) & D_00776D5C)) == (temp_a6 + (((temp_a4 + temp_t1) & temp_a5) << temp_a0))) var_t2 = 0;
            else var_t2 = 3;
            temp_a3_2 = ((var_t0 + D_00776D44) - temp_a4) & temp_a5;
            var_s4 = (temp_t3 + (var_a7 * 0x10)) & 0x0FFFFFFF;
            var_s3 = (u32) ((temp_a6 + (var_a7 << temp_a0)) - var_s1) >> 4;
            var_s2 = (var_s2 & 0x8FFFFFFF) | (var_t2 << 28);
            var_v1_2 = 0;
            if ((temp_a3_2 < 0) || (temp_a3_2 >= temp_t1)) {
                var_v1_2 = 1;
            }
            if (var_v1_2 != 0) {
                M2C_FIELD(arg0, u32 *, 0x2C) = var_t0;
                M2C_FIELD(arg0, s32 *, 0x30) = (s32) (temp_t1 + 1);
            }
        }
    }
    temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x10);
    if ((temp_v1_2 != 0) && (M2C_FIELD(arg0, s32 *, 0x14) != 0)) {
        *(volatile s32 *)0x1000B010 = temp_v1_2;
        __asm__ volatile("sync" : : : "memory");
        *(volatile s32 *)0x1000B020 = M2C_FIELD(arg0, s32 *, 0x14);
        __asm__ volatile("sync" : : : "memory");
        func_005038D8();
        temp_a1 = *(volatile s32 *)0x1000F520;
        *(volatile s32 *)0x1000F590 = temp_a1 | 0x10000;
        __asm__ volatile("sync" : : : "memory");
        *(volatile s32 *)0x1000B000 = M2C_FIELD(arg0, s32 *, 0x18) | 0x100;
        __asm__ volatile("sync" : : : "memory");
        *(volatile s32 *)0x1000F590 = temp_a1;
        __asm__ volatile("sync" : : : "memory");
        func_00503928();
    }
    if (M2C_FIELD(arg0, s32 *, 0x30) != 0) {
        func_004CC168(temp_s5 & 0x7F);
    }
    *(volatile u32 *)0x1000B410 = var_s1;
    __asm__ volatile("sync" : : : "memory");
    *(volatile s32 *)0x1000B430 = var_s4;
    __asm__ volatile("sync" : : : "memory");
    *(volatile u32 *)0x1000B420 = var_s3;
    __asm__ volatile("sync" : : : "memory");
    if (M2C_FIELD(arg0, s32 *, 0x30) != 0) {
        func_005038D8();
        temp_a1_2 = *(volatile s32 *)0x1000F520;
        *(volatile s32 *)0x1000F590 = (s32) (temp_a1_2 | 0x10000);
        __asm__ volatile("sync" : : : "memory");
        *(volatile s32 *)0x1000B400 = var_s2 | 0x100;
        __asm__ volatile("sync" : : : "memory");
        *(volatile s32 *)0x1000F590 = temp_a1_2;
        __asm__ volatile("sync" : : : "memory");
        func_00503928();
    }
    *(volatile s32 *)0x10002010 = M2C_FIELD(arg0, s32 *, 0x20);
    __asm__ volatile("sync" : : : "memory");
    func_004FA840(M2C_FIELD(arg0, s32 *, 0x38));
    return 0;
}

}
