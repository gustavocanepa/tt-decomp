#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_002CF678();                            /* extern */

struct func_0033F578_arg0 {
    char pad0[0xE40];
    s32 unkE40;
};

void func_0033F578(struct func_0033F578_arg0 *arg0) {
    func_002CF678();
    arg0->unkE40 = 1;
}
