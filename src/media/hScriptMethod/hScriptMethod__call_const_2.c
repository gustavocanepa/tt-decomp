/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002B1AB8(s32, s32);                    /* extern */
s32 func_002BAD00(s32, s32, s32, s32, s32);     /* extern */

struct hScriptMethod__virtual_14_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void hScriptMethod__call_const_2(void *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_002B1AB8(*arg1, arg0 + 0xC);
    func_002BAD00(*arg1, ((struct hScriptMethod__virtual_14_arg0 *)arg0)->unkC + 0x10, arg3, arg4, arg2);
}
