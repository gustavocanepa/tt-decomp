#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00579898[];
struct func_005115A8_arg0 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_005115A8(struct func_005115A8_arg0 *arg0) {
    s32 temp_v0;

    if (arg0 != NULL) {
        temp_v0 = *(s32 *)(s32)D_00579898;
        arg0->unkC = temp_v0;
        *(s32 *)(s32)D_00579898 = (s32) arg0;
    }
    return *(s32 *)(s32)D_00579898;
}
