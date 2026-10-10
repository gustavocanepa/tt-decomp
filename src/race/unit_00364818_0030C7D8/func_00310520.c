#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00310510(s32);                         /* extern */

struct func_00310520_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_00310520(struct func_00310520_arg0 *arg0) {
    func_00310510(arg0->unk10 + 0x240);
}
