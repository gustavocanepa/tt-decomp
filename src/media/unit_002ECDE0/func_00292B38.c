#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00294F40(s32);                         /* extern */

struct func_00292B38_arg0 {
    char pad0[0x78];
    s32 unk78;
};

void func_00292B38(struct func_00292B38_arg0 *arg0) {
    func_00294F40(arg0->unk78);
}
