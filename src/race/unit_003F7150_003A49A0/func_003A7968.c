#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A7968_arg0 {
    char pad0[0x30];
    f32 unk30;
    char pad34[0x34];
    f32 unk68;
    char pad6C[0x18];
    s32 unk84;
};

f32 func_003A7968(struct func_003A7968_arg0 *arg0) {
    if (arg0->unk84 < 2) {
        return arg0->unk30;
    }
    return arg0->unk68;
}
