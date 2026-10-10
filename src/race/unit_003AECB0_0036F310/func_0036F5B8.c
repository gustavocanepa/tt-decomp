#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0036F1F0(s32, s32);                    /* extern */
s32 func_003E3A60();                            /* extern */

struct func_0036F5B8_arg0 {
    char pad0[0x694];
    s32 unk694;
};
struct func_0036F5B8_arg1 {
    char pad0[0x694];
    s32 unk694;
};

void *func_0036F5B8(void *arg0, void *arg1) {
    func_003E3A60();
    func_0036F1F0(arg0 + 0x680, arg1 + 0x680);
    ((struct func_0036F5B8_arg0 *)arg0)->unk694 = (s32) ((struct func_0036F5B8_arg1 *)arg1)->unk694;
    return arg0;
}
