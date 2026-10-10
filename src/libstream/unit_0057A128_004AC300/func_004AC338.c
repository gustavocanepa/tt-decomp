#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AC300(s32);                             /* extern */

struct func_004AC338_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_004AC338(struct func_004AC338_arg0 *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = func_004AC300(arg1);
}
