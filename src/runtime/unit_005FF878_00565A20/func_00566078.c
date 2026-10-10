#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00566078_arg0 {
    char pad0[0x18];
    s32 *unk18;
};

s32 func_00566078(struct func_00566078_arg0 *arg0) {
    return *arg0->unk18;
}
