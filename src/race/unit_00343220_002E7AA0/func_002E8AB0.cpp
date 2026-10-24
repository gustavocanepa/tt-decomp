#include "types.h"

extern "C" void func_002E8AB0(char *arg0, char *arg1) {
    if (*(s32 *)(arg0 + 4) != 0 && *(s32 *)(arg1 + 4) != 0) {
        __builtin_memcpy(*(void **)(arg0 + 0x60), *(void **)(arg1 + 0x60), 0x10000);
    }
}
