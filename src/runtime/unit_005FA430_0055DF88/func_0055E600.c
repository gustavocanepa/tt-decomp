#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D5D88[];
struct func_0055E600_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_0055E600(struct func_0055E600_arg0 *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = (s32)D_005D5D88;
}
