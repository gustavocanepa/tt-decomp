/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104BA8();                            /* extern */
s32 func_00107280(void *);                      /* extern */
s32 func_00472268(s32, s32);            /* extern */

struct func_001B26F8_arg0 {
    char pad0[0x80];
    s32 unk80;
    char pad84[0x60];
    s32 unkE4;
};

void func_001B26F8(void *arg0) {
    if ((((struct func_001B26F8_arg0 *)arg0)->unkE4 != 0) && (((struct func_001B26F8_arg0 *)arg0)->unk80 == 1)) {
        func_00104BA8();
        func_00107280(arg0 + 0x40);
        ((struct func_001B26F8_arg0 *)arg0)->unk80 = 0;
        func_00472268(2, 1);
        func_00472268(3, 1);
    }
}
