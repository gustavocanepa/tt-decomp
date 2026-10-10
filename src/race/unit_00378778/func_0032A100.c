#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0032A100_arg0 {
    char pad0[0x1BA];
    u8 unk1BA;
};

u8 func_0032A100(struct func_0032A100_arg0 *arg0) {
    return arg0->unk1BA;
}
