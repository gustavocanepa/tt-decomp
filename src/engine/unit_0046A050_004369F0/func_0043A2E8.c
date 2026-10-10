#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00472268(s32, s32);            /* extern */

void func_0043A2E8(s32 arg0, s32 arg1) {
    if (arg1 != 1) {
        func_00472268(4, 0);
        func_00472268(5, 0);
        return;
    }
    func_00472268(4, 2);
    func_00472268(5, 2);
}
