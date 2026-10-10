#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0036F1B0(s32);                         /* extern */
s32 func_003E32B8();                            /* extern */

struct func_0036F588_arg0 {
    char pad0[0x694];
    s32 unk694;
};

void func_0036F588(void *arg0) {
    func_003E32B8();
    func_0036F1B0(arg0 + 0x680);
    ((struct func_0036F588_arg0 *)arg0)->unk694 = 0;
}
