#include "types.h"
#define NULL 0

extern "C" {
s32 func_00357310(void *);
void func_004A6500(void *, char *, ...);
extern char D_005F6EC8[];
extern char D_005F6ED8[];
extern char D_005F6EE8[];
}

extern "C" void func_003734F8(void *arg0) {
    s8 sp[0x20];
    s32 *var_v1;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_a0;
    s32 var_s1;
    s32 *var_s0;

    if (((s32 *)arg0)[0x40 / 4] == 0) {
        temp_s0 = func_00357310(D_005F6EC8);
        temp_v0 = func_00357310(D_005F6ED8);
        ((s32 *)arg0)[0x1C / 4] = temp_s0;
        var_a0 = 1;
        var_v1 = (s32 *)((s8 *)arg0 + 0x20);
        for (; var_a0 < 6; var_a0++) {
            *var_v1 = temp_v0;
            var_v1 += 1;
        }
    } else {
        var_s1 = 0;
        do {
            func_004A6500(sp, D_005F6EE8, var_s1);
            ((s32 *)arg0)[var_s1 + 7] = func_00357310(sp);
            var_s1 += 1;
        } while (var_s1 < 6);
    }
    ((s32 *)arg0)[0x44 / 4] = 1;
}
