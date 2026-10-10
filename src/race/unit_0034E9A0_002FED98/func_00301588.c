#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00301398();                            /* extern */
s32 func_00301538(void *);                      /* extern */

struct func_00301588_arg0 {
    char pad0[0x58A];
    s8 unk58A;
};

void func_00301588(struct func_00301588_arg0 *arg0) {
    if (arg0->unk58A == 2) {
        return;
    }
    func_00301398();
    func_00301538(arg0);
}
