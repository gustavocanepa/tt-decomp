#include "types.h"
extern char D_005794F0[];
void func_00106AF0(char *a, s32 b, s32 c, s32 d, s32 e);
void func_00478C98(s32 a);
s32 func_003FCE58(char *arg0) {
    func_00106AF0(D_005794F0, 1, 0, 0x280, 0x1C0);
    func_00478C98(0x17);
    return *(s32 *)(arg0 + 0x1718) != 0;
}
