#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104868(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D5BA8[];
struct func_003900C8_arg0 {
    char pad0[0x2428];
    s32 unk2428;
};

void func_003900C8(void *arg0, s32 arg1) {
    ((struct func_003900C8_arg0 *)arg0)->unk2428 = (s32)D_005D5BA8;
    func_00104868(arg0 + 0xC8, 2);
    func_00104868(arg0 + 0x8C, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
