#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DB400[];
struct fpool__structor_1_arg0 {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x8];
    s32 unk1C;
};

void fpool__structor_1(struct fpool__structor_1_arg0 *arg0, s32 arg1) {
    arg0->unk1C = (s32)D_005DB400;
    func_004A45D0(arg0->unk10);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
