#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0057B820[];
struct func_0053C530_arg0 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_0053C530(struct func_0053C530_arg0 *arg0) {
    if (arg0 != NULL) {
        arg0->unkC = *(s32 *)(s32)D_0057B820;
        *(s32 *)(s32)D_0057B820 = (s32)arg0;
    }
    return *(s32 *)(s32)D_0057B820;
}
