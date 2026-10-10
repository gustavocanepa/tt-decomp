#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005576C8_arg0 {
    char pad0[0x34];
    u8 unk34;
    u8 unk35;
};

void func_005576C8(struct func_005576C8_arg0 *arg0) {
    arg0->unk35 = (u8) arg0->unk34;
}
