#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005CF9B8[];
struct func_00357E48_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_00357E48(struct func_00357E48_arg0 *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = (s32)D_005CF9B8;
}
