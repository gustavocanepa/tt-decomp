#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00564B78_arg0 {
    char pad0[0x40];
    s64 unk40;
};

void func_00564B78(struct func_00564B78_arg0 *arg0, s32 arg1) {
    arg0->unk40 = (s64) (arg1 + arg0->unk40);
}
