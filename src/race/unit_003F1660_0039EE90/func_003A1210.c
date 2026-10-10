#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A1210_arg0 {
    char pad0[0x11D];
    s8 unk11D;
    s16 unk11E;
};

void func_003A1210(struct func_003A1210_arg0 *arg0) {
    arg0->unk11D = 0;
    arg0->unk11E = 0;
}
