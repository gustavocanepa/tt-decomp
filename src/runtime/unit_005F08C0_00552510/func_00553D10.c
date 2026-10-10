#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553D10_arg0 {
    char pad0[0x1CC];
    f32 unk1CC;
};

f32 func_00553D10(struct func_00553D10_arg0 *arg0) {
    return arg0->unk1CC;
}
