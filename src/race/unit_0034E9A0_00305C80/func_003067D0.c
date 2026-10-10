#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003067D0_arg0 {
    char pad0[0x62A];
    u16 unk62A;
};

u16 func_003067D0(struct func_003067D0_arg0 *arg0) {
    return arg0->unk62A;
}
