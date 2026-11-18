#include "types.h"
extern char D_005D6E30[];
void func_003AAE28(char *a);
void func_003AAD98(char *arg0) {
    *(char **)(arg0 + 0x14) = D_005D6E30;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    func_003AAE28(arg0);
}
