#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00205D10();                            /* extern */
s32 func_00205D70();                            /* extern */

struct func_00253E90_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

void func_00253E90(struct func_00253E90_arg0 *arg0) {
    if (arg0->unkD4 == 0) {
        func_00205D70();
        return;
    }
    func_00205D10();
}
