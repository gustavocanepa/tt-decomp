#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00304FD0_arg0 {
    char pad0[0x24114];
    s16 unk24114;
};

s32 SetupHumanInterfaceParameters(struct func_00304FD0_arg0 *arg0) {
    arg0->unk24114 = 0;
    return 0;
}
