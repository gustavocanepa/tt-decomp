#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0041E158(s32);                         /* extern */

struct func_0041A630_arg0 {
    s32 unk0;
    char pad4[0x88];
    s32 unk8C;
};

void func_0041A630(struct func_0041A630_arg0 *arg0) {
    arg0->unk8C = 1;
    func_0041E158(arg0->unk0);
}
