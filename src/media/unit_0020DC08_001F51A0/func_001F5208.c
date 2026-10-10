#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001F5230();                                /* extern */

struct func_001F5208_arg0 {
    char pad0[0x30];
    s32 unk30;
};

s32 func_001F5208(struct func_001F5208_arg0 *arg0) {
    arg0->unk30 = func_001F5230();
}
