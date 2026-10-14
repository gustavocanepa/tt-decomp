#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0057AB30[];
struct func_005247B0_arg0 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_005247B0(struct func_005247B0_arg0 *arg0) {
    if (arg0 != NULL) {
        arg0->unkC = *(s32 *)(s32)D_0057AB30;
        *(s32 *)(s32)D_0057AB30 = (s32)arg0;
    }
    return *(s32 *)(s32)D_0057AB30;
}
