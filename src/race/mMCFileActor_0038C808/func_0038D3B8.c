#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0038D3B8_arg0_unk4 {
    char pad0[0x60];
    s32 *unk60;
};
struct func_0038D3B8_arg0 {
    char pad0[0x4];
    struct func_0038D3B8_arg0_unk4 *unk4;
};

s32 func_0038D3B8(struct func_0038D3B8_arg0 *arg0) {
    return *arg0->unk4->unk60 < 2;
}
