#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00322020_arg0 {
    char pad0[0x15C];
    f32 unk15C;
};

f32 func_00322020(struct func_00322020_arg0 *arg0) {
    return arg0->unk15C;
}
