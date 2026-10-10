#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00412718_arg0 {
    s32 unk0;
    void *unk4;
};

void func_00412718(struct func_00412718_arg0 *arg0) {
    arg0->unk4 = arg0;
    arg0->unk0 = -1;
}
