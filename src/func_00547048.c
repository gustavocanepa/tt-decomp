#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00547048_arg0 {
    char pad0[0xC];
    s32 unkC;
};

extern char D_0057C060[];
s32 func_00547048(struct func_00547048_arg0 *arg0) {
    s32 temp_v0;

    if (arg0 != NULL) {
        temp_v0 = *(s32 *)(s32)D_0057C060;
        arg0->unkC = temp_v0;
        *(s32 *)(s32)D_0057C060 = (s32) arg0;
    }
    return *(s32 *)(s32)D_0057C060;
}
