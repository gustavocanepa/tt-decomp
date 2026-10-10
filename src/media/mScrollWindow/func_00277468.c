#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00275DE8();                    /* extern */

struct func_00277468_arg0 {
    char pad0[0xEC];
    s32 unkEC;
    s32 unkF0;
};

void func_00277468(void *arg0, s32 arg1) {
    func_00275DE8(arg0 + 0xF4);
    func_00275DE8(arg0 + 0x12C, arg1);
    ((struct func_00277468_arg0 *)arg0)->unkF0 = 0;
    ((struct func_00277468_arg0 *)arg0)->unkEC = 0;
}
