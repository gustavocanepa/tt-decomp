#include "types.h"
void func_004A4F00(char *a);
void func_004AEA48(char *arg0) {
    if (*(s32 *)(arg0 + 0x28) != 0) {
        func_004A4F00(arg0);
        return;
    }
    *(s32 *)(arg0 + 0x2C) = 1;
}
