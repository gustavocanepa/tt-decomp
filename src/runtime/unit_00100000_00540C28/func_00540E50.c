#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00540E50_arg0 {
    char pad0[0x34];
    s32 unk34;
};

void func_00540E50(struct func_00540E50_arg0 *arg0, s32 arg1) {
    arg0->unk34 = arg1;
}
