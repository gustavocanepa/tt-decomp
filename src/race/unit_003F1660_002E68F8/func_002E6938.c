#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6938_arg0_unk10 {
    char pad0[0x118];
    f32 unk118;
};
struct func_002E6938_arg0 {
    char pad0[0x10];
    struct func_002E6938_arg0_unk10 *unk10;
};

f32 func_002E6938(struct func_002E6938_arg0 *arg0) {
    return arg0->unk10->unk118;
}
