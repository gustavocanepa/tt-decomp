#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_0033C458();                            /* extern */

struct func_002CF678_arg0 {
    char pad0[0xE40];
    s32 unkE40;
};

void func_002CF678(struct func_002CF678_arg0 *arg0) {
    func_0033C458();
    arg0->unkE40 = 1;
}
