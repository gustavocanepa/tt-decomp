#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003FBF98_arg0 {
    char pad0[0x8230];
    s64 unk8230;
};

void func_003FBF98(struct func_003FBF98_arg0 *arg0, s64 arg1) {
    arg0->unk8230 = (s64) (arg1 ^ 0x7A726F706C6C525Eu);
}
