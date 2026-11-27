#include "types.h"

extern "C" void func_004627F0(char *arg0, s32 arg1);

extern "C" void func_00462838(char *arg0) {
    func_004627F0(arg0, 0);
    *(s32 *)(arg0 + 0x984) = 0;
}
