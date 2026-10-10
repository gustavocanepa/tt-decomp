#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00381C28_arg1 {
    s32 unk0;
    s32 unk4;
};

s32 func_00381C28(s32 arg0, struct func_00381C28_arg1 *arg1) {
    if (arg1 != NULL) {
        arg1->unk0 = 0;
        arg1->unk4 = 0x64;
    }
    return 0;
}
