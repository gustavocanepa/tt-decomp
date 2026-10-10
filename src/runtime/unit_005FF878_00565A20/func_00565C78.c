#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C78_arg0 {
    char pad0[0x61];
    u8 unk61;
};

u8 func_00565C78(struct func_00565C78_arg0 *arg0) {
    return arg0->unk61;
}
