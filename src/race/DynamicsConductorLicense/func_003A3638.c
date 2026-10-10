#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A3638_arg0 {
    char pad0[0x2392E];
    u8 unk2392E;
};

u8 func_003A3638(struct func_003A3638_arg0 *arg0) {
    return arg0->unk2392E;
}
