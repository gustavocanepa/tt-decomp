/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047D090();                            /* extern */
s32 func_004A5618(s32);                         /* extern */

struct func_0047D150_arg0 {
    char pad0[0x94];
    s32 unk94;
    char pad98[0x8];
    s32 unkA0;
};

void func_0047D150(struct func_0047D150_arg0 *arg0) {
    func_0047D090();
    arg0->unkA0 = 0;
    func_004A5618(arg0->unk94);
}
