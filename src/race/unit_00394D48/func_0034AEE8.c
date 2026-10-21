#include "types.h"
char *func_0034C5E8(s32 a);
u16 func_0034AEE8(char *arg0) {
    if (*(s32 *)(arg0 + 0xB8) < 0) return 0;
    return *(u16 *)(*(char **)(func_0034C5E8(*(s32 *)(arg0 + 4)) + 0x9C) + (*(s32 *)(arg0 + 0xB8) << 5) + 0xE);
}
