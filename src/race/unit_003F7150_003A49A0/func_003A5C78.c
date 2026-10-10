#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A5C78_arg0_unk10 {
    char pad0[0x111E];
    u8 unk111E;
};
struct func_003A5C78_arg0 {
    char pad0[0x10];
    struct func_003A5C78_arg0_unk10 *unk10;
};

u8 func_003A5C78(struct func_003A5C78_arg0 *arg0) {
    return arg0->unk10->unk111E;
}
