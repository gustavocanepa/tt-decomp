#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00381DF8_arg1 {
    s32 unk0;
    s32 unk4;
};

s32 func_00381DF8(s32 arg0, struct func_00381DF8_arg1 *arg1) {
    if (arg1 != NULL) {
        arg1->unk4 = 0;
        arg1->unk0 = -0x19;
    }
    return 0;
}
