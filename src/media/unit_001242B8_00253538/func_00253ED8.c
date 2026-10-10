#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00253ED8_arg0 {
    char pad0[0xD4];
    s32 unkD4;
    char padD8[0xC];
    f32 unkE4;
    f32 unkE8;
};

f32 func_00253ED8(struct func_00253ED8_arg0 *arg0) {
    if (arg0->unkD4 == 0) {
        return arg0->unkE8;
    }
    return arg0->unkE4;
}
