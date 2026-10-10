#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001FA1A8(void *);                      /* extern */
s32 func_0020B378();                            /* extern */

struct func_001FA210_arg0 {
    char pad0[0x140];
    s32 unk140;
};
struct func_001FA210_arg1_unk10 {
    char pad0[0xDE];
    s16 unkDE;
};
struct func_001FA210_arg1 {
    char pad0[0x10];
    struct func_001FA210_arg1_unk10 *unk10;
};

void func_001FA210(struct func_001FA210_arg0 *arg0, struct func_001FA210_arg1 *arg1) {
    func_0020B378();
    func_001FA1A8(arg0);
    arg0->unk140 = (s32) (arg1->unk10->unkDE < 4);
}
