/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004FE730_arg0 {
    void *unk0;
    s32 unk4;
};
struct func_004FE730_temp_a1 {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x4];
    s32 unk18;
};

s32 func_004FE730(struct func_004FE730_arg0 *arg0) {
    struct func_004FE730_temp_a1 *temp_a1;

    temp_a1 = arg0->unk0;
    if ((temp_a1 == NULL) || (arg0->unk4 != temp_a1->unk18) || !(temp_a1->unk10 & 1)) {
        return 0;
    }
    return 1;
}
