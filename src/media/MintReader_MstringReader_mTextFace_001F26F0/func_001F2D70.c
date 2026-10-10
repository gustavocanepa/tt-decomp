#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00259558(s32);                         /* extern */

struct func_001F2D70_arg0 {
    char pad0[0x12C];
    s32 unk12C;
};

void func_001F2D70(struct func_001F2D70_arg0 *arg0) {
    func_00259558(arg0->unk12C);
}
