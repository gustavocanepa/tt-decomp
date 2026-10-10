#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00564C18_arg0 {
    char pad0[0x8C];
    u8 unk8C;
};

u8 func_00564C18(struct func_00564C18_arg0 *arg0) {
    return arg0->unk8C;
}
