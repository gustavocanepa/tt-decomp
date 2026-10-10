#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051BFD8_arg0_unk10 {
    char pad0[0x16FC];
    s16 unk16FC;
};
struct func_0051BFD8_arg0 {
    char pad0[0x10];
    struct func_0051BFD8_arg0_unk10 *unk10;
};

s16 func_0051BFD8(struct func_0051BFD8_arg0 *arg0) {
    return arg0->unk10->unk16FC;
}
