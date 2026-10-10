#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00460638(s32, s32, s32);               /* extern */
s32 func_00555E58(void *, s32);                 /* extern */
s32 func_0056D910(void *, s32);                 /* extern */
s32 func_0056D948(void *, s32);                 /* extern */
s32 func_0056D980(s32, s32);                    /* extern */

struct func_00460530_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x8];
    u16 unk10;
    char pad12[0x2];
    s32 unk14;
    s32 unk18;
};

void func_00460530(void *arg0) {
    s32 temp_s0;
    s32 temp_s2;
    s32 var_s3;

    temp_s2 = arg0 - ((struct func_00460530_arg0 *)arg0)->unk4;
    if (temp_s2 != 0) {
        ((struct func_00460530_arg0 *)arg0)->unk4 = arg0;
        func_00555E58(arg0 + 8, temp_s2);
        func_0056D910(arg0 + 0x18, temp_s2);
        if (((struct func_00460530_arg0 *)arg0)->unk14 != 0) {
            func_0056D948(arg0 + 0x14, temp_s2);
            var_s3 = 0;
            if (((struct func_00460530_arg0 *)arg0)->unk10 != 0) {
                do {
                    temp_s0 = var_s3 * 4;
                    var_s3 += 1;
                    func_0056D980(((struct func_00460530_arg0 *)arg0)->unk14 + temp_s0, temp_s2);
                    func_00460638(*(s32 *)(temp_s0 + ((struct func_00460530_arg0 *)arg0)->unk14), temp_s2, ((struct func_00460530_arg0 *)arg0)->unk18);
                } while (var_s3 < (s32) ((struct func_00460530_arg0 *)arg0)->unk10);
            }
        }
    }
}
