#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003ECAB0(void *);                      /* extern */
s32 func_003EE7A0(void *);                      /* extern */

extern char D_005D73F0[];
struct func_003ECA08_arg0 {
    char pad0[0x1DE0];
    s32 unk1DE0;
    s32 unk1DE4;
};

void func_003ECA08(void *arg0) {
    ((struct func_003ECA08_arg0 *)arg0)->unk1DE4 = (s32)D_005D73F0;
    func_003EE7A0(arg0 + 0xBD8);
    func_003ECAB0(arg0);
    ((struct func_003ECA08_arg0 *)arg0)->unk1DE0 = 0;
}
