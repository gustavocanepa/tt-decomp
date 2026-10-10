#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D74D8_arg0 {
    char pad0[0x50];
    s32 unk50;
};

void func_001D74D8(struct func_001D74D8_arg0 *arg0, s32 arg1) {
    arg0->unk50 = arg1;
}
