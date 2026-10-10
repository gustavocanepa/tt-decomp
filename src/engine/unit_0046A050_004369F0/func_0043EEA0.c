#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0043EEA0_arg0 {
    s32 unk0;
    s32 unk4;
};
struct func_0043EEA0_arg1 {
    s32 unk0;
    s32 unk4;
};

s32 func_0043EEA0(struct func_0043EEA0_arg0 *arg0, struct func_0043EEA0_arg1 *arg1) {
    if (arg0->unk0 == arg1->unk0) {
        return arg0->unk4 == arg1->unk4;
    }
    return 0;
}
