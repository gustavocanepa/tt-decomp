#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005861F0[];
struct func_0042F440_arg0 {
    void *unk0;
    void *unk4;
    void *unk8;
};

void func_0042F440(struct func_0042F440_arg0 *arg0, void *arg1, void *arg2) {
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
    arg0->unk0 = (void *) *(void **)(s32)D_005861F0;
    *(void **)(s32)D_005861F0 = arg0;
}
