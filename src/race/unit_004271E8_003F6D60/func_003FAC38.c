#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FAC38(s32 *arg0) {
    return *(s32 *)(0x585608 + (*(s32 *)arg0 * 4));
}
