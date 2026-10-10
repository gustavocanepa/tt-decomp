#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */
s32 func_0050E1A8(void *);                      /* extern */

struct func_002E13C8_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_002E13C8(struct func_002E13C8_arg0 *arg0, s32 arg1) {
    func_004A45D0(arg0->unk0);
    func_004A45D0(arg0->unk4);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
