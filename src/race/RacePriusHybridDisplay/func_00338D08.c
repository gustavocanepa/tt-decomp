#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00338D08_arg0 {
    char pad0[0x10D8];
    s32 unk10D8;
};

u32 func_00338D08(struct func_00338D08_arg0 *arg0) {
    return (u32) ~arg0->unk10D8 >> 0x1F;
}
