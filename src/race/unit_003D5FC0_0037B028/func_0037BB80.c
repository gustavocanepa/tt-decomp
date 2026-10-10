#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0037BB80_arg0_unk4 {
    char pad0[0x6E4];
    f32 unk6E4;
};
struct func_0037BB80_arg0 {
    char pad0[0x4];
    struct func_0037BB80_arg0_unk4 *unk4;
};

f32 func_0037BB80(struct func_0037BB80_arg0 *arg0) {
    return arg0->unk4->unk6E4;
}
