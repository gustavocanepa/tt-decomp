#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055A608_arg0 {
    char pad0[0x11E8];
    s32 unk11E8;
};

void func_0055A608(struct func_0055A608_arg0 *arg0, s32 arg1) {
    arg0->unk11E8 = arg1;
}
