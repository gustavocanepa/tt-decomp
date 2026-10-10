#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0055AD50_arg0 {
    char pad0[0xBC];
    s32 unkBC;
};

s32 func_0055AD50(struct func_0055AD50_arg0 *arg0) {
    return arg0->unkBC != 0;
}
