#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D7518_arg0 {
    char pad0[0x1E0];
    s32 unk1E0;
};

void func_001D7518(struct func_001D7518_arg0 *arg0, s32 arg1) {
    arg0->unk1E0 = arg1;
}
