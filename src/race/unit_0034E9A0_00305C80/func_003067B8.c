#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003067B8_arg0 {
    char pad0[0x62A];
    s16 unk62A;
};

void func_003067B8(struct func_003067B8_arg0 *arg0, s32 arg1) {
    arg0->unk62A = (s16) (arg1 * 0x3C);
}
