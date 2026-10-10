#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002E6E60(void *);                      /* extern */
void *func_002F04D8(void *, s32);                   /* extern */

struct func_003A4E80_arg0 {
    char pad0[0x23920];
    u8 unk23920;
    char pad23921[0x47];
    s32 unk23968;
};
struct func_003A4E80_temp_v0 {
    char pad0[0x58A];
    s8 unk58A;
};

void func_003A4E80(struct func_003A4E80_arg0 *arg0) {
    s32 var_s0;
    struct func_003A4E80_temp_v0 *temp_v0;

    if (arg0->unk23920 != 0) {
        var_s0 = 0;
        if (arg0->unk23968 > 0) {
            do {
                temp_v0 = func_002F04D8(arg0, var_s0);
                var_s0 += 1;
                if (temp_v0->unk58A == 2) {
                    func_002E6E60(temp_v0);
                }
            } while (var_s0 < arg0->unk23968);
        }
    }
}
