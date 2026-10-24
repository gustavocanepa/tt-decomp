#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0057C0C4[];
struct func_00297838_arg0 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_00297838(struct func_00297838_arg0 *arg0) {
    if (arg0 != NULL) {
        arg0->unk10 = *(s32 *)(s32)D_0057C0C4;
        *(s32 *)(s32)D_0057C0C4 = (s32)arg0;
    }
    return *(s32 *)(s32)D_0057C0C4;
}
