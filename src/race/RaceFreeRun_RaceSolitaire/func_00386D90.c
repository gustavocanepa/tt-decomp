#include "types.h"
void AutomobileControlRecord__Manager__load(char *a, char *b, s32 c);
void func_00386D90(char *arg0, char *arg1) {
    char *s = arg0 + 0xE54C;
    AutomobileControlRecord__Manager__load(arg0 + 0xE620, arg1 + 0x1A24, 1);
    *(s32 *)(s + 0x1D0) = 0;
}
