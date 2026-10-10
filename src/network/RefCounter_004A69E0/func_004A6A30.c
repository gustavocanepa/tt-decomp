#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004A6A30_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_004A6A30(struct func_004A6A30_arg0 *arg0) {
    arg0->unk0 = (s32) arg0->unk4;
    return 0;
}
