#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005ADA40[];
struct func_001ABB98_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_001ABB98(struct func_001ABB98_arg0 *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)D_005ADA40;
}
