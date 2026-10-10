#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00518D28_arg0 {
    char pad0[0x58];
    f32 unk58;
};

f32 func_00518D28(struct func_00518D28_arg0 *arg0) {
    return arg0->unk58;
}
