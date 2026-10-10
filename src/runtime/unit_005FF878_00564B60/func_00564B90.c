#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00564B90_arg0 {
    char pad0[0x50];
    s32 unk50;
};

void func_00564B90(struct func_00564B90_arg0 *arg0, s32 arg1) {
    arg0->unk50 = (s32) (arg0->unk50 + arg1);
}
