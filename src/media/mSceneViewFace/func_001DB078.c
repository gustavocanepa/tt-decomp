#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001DB078_arg0 {
    char pad0[0x38];
    s32 *unk38;
    s32 unk3C;
};

void func_001DB078(struct func_001DB078_arg0 *arg0, s32 *arg1) {
    arg0->unk38 = arg1;
    if (arg1 != NULL) {
        arg0->unk3C = (s32) *arg1;
        return;
    }
    arg0->unk3C = 0;
}
