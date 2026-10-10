#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565D08_arg0 {
    char pad0[0x73];
    u8 unk73;
};

u8 func_00565D08(struct func_00565D08_arg0 *arg0) {
    return arg0->unk73;
}
