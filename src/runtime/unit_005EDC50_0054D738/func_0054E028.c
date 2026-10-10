#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0054E028_arg0_unk24 {
    char pad0[0x3C];
    s32 unk3C;
};
struct func_0054E028_arg0 {
    char pad0[0x24];
    struct func_0054E028_arg0_unk24 *unk24;
};

s32 func_0054E028(struct func_0054E028_arg0 *arg0) {
    return arg0->unk24->unk3C;
}
