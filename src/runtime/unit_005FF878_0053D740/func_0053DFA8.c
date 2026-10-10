#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053DFA8_arg0 {
    char pad0[0xE0];
    s32 unkE0;
};

void func_0053DFA8(struct func_0053DFA8_arg0 *arg0, s32 arg1) {
    arg0->unkE0 = arg1;
}
