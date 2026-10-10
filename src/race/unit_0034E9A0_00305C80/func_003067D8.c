#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003067D8_arg0 {
    char pad0[0x62A];
    u16 unk62A;
};

u16 func_003067D8(struct func_003067D8_arg0 *arg0) {
    u16 temp_v1;

    temp_v1 = arg0->unk62A;
    arg0->unk62A = (u16) (temp_v1 - (temp_v1 != 0));
    return temp_v1;
}
