#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C38_arg0 {
    char pad0[0x55];
    u8 unk55;
};

u8 func_00565C38(struct func_00565C38_arg0 *arg0) {
    return arg0->unk55;
}
