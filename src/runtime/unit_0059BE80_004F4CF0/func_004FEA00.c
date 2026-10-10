/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005038D8();                            /* extern */
s32 func_00503928();                            /* extern */

struct func_004FEA00_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    void *unkC;
};
struct func_004FEA00_temp_s1 {
    char pad0[0x3C];
    void *unk3C;
};

void *func_004FEA00(struct func_004FEA00_arg0 *arg0) {
    struct func_004FEA00_temp_s1 *temp_s1;

    func_005038D8();
    temp_s1 = arg0->unkC;
    if (temp_s1 == NULL) {
        arg0->unk4 = 0;
    } else {
        arg0->unk4 = 1;
        arg0->unkC = (void *) temp_s1->unk3C;
    }
    func_00503928();
    return temp_s1;
}
