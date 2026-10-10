#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00304FC0_arg0 {
    char pad0[0x23926];
    u8 unk23926;
};

u8 func_00304FC0(struct func_00304FC0_arg0 *arg0) {
    return arg0->unk23926;
}
