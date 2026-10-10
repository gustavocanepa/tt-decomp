#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005C7A18[];
struct func_002C0EC8_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_002C0EC8(struct func_002C0EC8_arg0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = (s32)D_005C7A18;
}
