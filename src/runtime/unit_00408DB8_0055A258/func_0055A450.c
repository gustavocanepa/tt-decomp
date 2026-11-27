#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0036F628(s32);                         /* extern */

struct func_0055A450_arg0 {
    char pad0[0xD40];
    s32 unkD40;
};

void func_0055A450(void *arg0) {
    func_0036F628(((((struct func_0055A450_arg0 *)arg0)->unkD40 * 0x6A0) + arg0));
}
