#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003A4860();                            /* extern */

struct func_003A4418_arg0 {
    char pad0[0x20A35];
    s8 unk20A35;
};

void func_003A4418(struct func_003A4418_arg0 *arg0) {
    func_003A4860();
    arg0->unk20A35 = 0;
}
