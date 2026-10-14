#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_002F04D8(s32, s32);                  /* extern */
s32 func_002F1118(void *, s32);                 /* extern */

struct func_003A3458_temp_v0 {
    char pad0[0x7A0];
    s8 unk7A0;
};

void func_003A3458(void *arg0, s32 arg1) {
    s32 var_s0;
    struct func_003A3458_temp_v0 *temp_v0;

    var_s0 = 0;
    if (*(s32 *)((char *)arg0 + 0x23968) > 0) {
        do {
            temp_v0 = func_002F04D8(arg0, var_s0);
            var_s0 += 1;
            temp_v0->unk7A0 = 0;
        } while (var_s0 < *(s32 *)((char *)arg0 + 0x23968));
    }
    func_002F1118(arg0, arg1);
}
