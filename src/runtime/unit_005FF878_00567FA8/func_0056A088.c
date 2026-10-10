#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0056A088_arg0_unk4 {
    char pad0[0xA];
    u16 unkA;
};
struct func_0056A088_arg0 {
    char pad0[0x4];
    struct func_0056A088_arg0_unk4 *unk4;
};

u16 func_0056A088(struct func_0056A088_arg0 *arg0) {
    return arg0->unk4->unkA;
}
