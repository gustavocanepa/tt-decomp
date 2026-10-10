#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0048CB10_arg0 {
    char pad0[0x78];
    s32 unk78;
};

void func_0048CB10(struct func_0048CB10_arg0 *arg0, s32 arg1) {
    arg0->unk78 = arg1;
}
