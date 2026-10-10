#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE878(s32);                     /* extern */
s32 func_004A53A8(s32);                             /* extern */
s32 func_004FB960(s32, void *);                     /* extern */

struct func_004A5618_arg0 {
    char pad0[0x30];
    s32 unk30;
};

s32 func_004A5618(struct func_004A5618_arg0 *arg0) {
    if (func_004FB960(func_004A53A8(arg0->unk30), arg0) == -1) {
        func_004AE878((s32)"EE StartThread failed.");
    }
}
