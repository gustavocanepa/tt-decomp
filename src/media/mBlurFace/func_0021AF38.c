#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0020B378();                            /* extern */

struct func_0021AF38_arg0 {
    char pad0[0xB8];
    s32 unkB8;
    s32 unkBC;
};

void func_0021AF38(struct func_0021AF38_arg0 *arg0) {
    func_0020B378();
    arg0->unkB8 = 0;
    arg0->unkBC = 0;
}
