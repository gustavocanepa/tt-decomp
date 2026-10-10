#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00447F50_arg0 {
    s32 (*unk0)(s32);
    s32 unk4;
};

void func_00447F50(struct func_00447F50_arg0 *arg0) {
    s32 (*temp_v0)(s32);

    temp_v0 = arg0->unk0;
    if (temp_v0 != NULL) {
        temp_v0(arg0->unk4);
    }
}
