#include "types.h"
void func_004C47F0(char *a);
void func_004C47C0(char *arg0) {
    char *t = arg0 + 0x1C;
    *(s32 *)(t + 4) = 0;
    *(s32 *)(t + 0) = 0;
    *(s32 *)(t + 8) = 0;
    *(s32 *)(t + 0xC) = 0;
    *(s32 *)(t + 0x10) = 0;
    *(s32 *)(t + 0x14) = 0;
    func_004C47F0(arg0);
}
