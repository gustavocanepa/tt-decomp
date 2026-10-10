#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562920_arg0 {
    char pad0[0x10FC];
    s32 unk10FC;
};

s32 func_00562920(struct func_00562920_arg0 *arg0) {
    return arg0->unk10FC;
}
