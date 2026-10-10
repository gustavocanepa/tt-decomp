#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_002FD378(s32);                           /* extern */
s32 func_0030E928();                                /* extern */

struct func_0030E9D8_temp_s1 {
    char pad0[0x620];
    s8 unk620;
    s8 unk621;
    s8 unk622;
    char pad623[0x7B];
    s16 unk69E;
};
struct func_0030E9D8_temp_v0 {
    char pad0[0x1];
    u8 unk1;
};

struct func_0030E9D8_arg0 {
    char pad0[0x10];
    s32 unk10;
};
struct func_0030E9D8_var_a0 {
    char pad0[0xB4];
    s32 unkB4;
    f32 unkB8;
    s32 unkBC;
};

void func_0030E9D8(void *arg0) {
    s32 var_a1;
    struct func_0030E9D8_temp_s1 *temp_s1;
    struct func_0030E9D8_temp_v0 *temp_v0;
    void *var_a0;

    if (func_0030E928() < 3) {
        temp_s1 = arg0 + 0x104;
        if (temp_s1->unk69E >= 0) {
            temp_v0 = func_002FD378(((struct func_0030E9D8_arg0 *)arg0)->unk10);
            var_a1 = 0;
            if (temp_v0->unk1 != 0) {
                var_a0 = arg0 + 0x164;
                do {
                    ((struct func_0030E9D8_var_a0 *)var_a0)->unkBC = 0;
                    var_a1 += 1;
                    ((struct func_0030E9D8_var_a0 *)var_a0)->unkB4 = 0;
                    ((struct func_0030E9D8_var_a0 *)var_a0)->unkB8 = 0x1.0000000000000p+0f;
                    var_a0 += 0xF4;
                } while (var_a1 < (s32) temp_v0->unk1);
            }
            temp_s1->unk621 = 0;
            temp_s1->unk622 = 0;
            temp_s1->unk620 = 0;
        }
    }
}
