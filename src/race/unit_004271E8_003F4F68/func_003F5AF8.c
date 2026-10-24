#include "types.h"
extern char D_005DCFA0[];
extern char D_005F9628[];
s32 func_004A8268(char *a, char *b);
s32 func_003F5AF8(void) {
    return func_004A8268(D_005DCFA0, D_005F9628) == 0 ? 0x64 : 1;
}
