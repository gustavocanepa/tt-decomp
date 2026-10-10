#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418258_arg0 {
    char pad0[0x2DC];
    f32 unk2DC;
};

f32 func_00418258(struct func_00418258_arg0 *arg0) {
    return arg0->unk2DC;
}
