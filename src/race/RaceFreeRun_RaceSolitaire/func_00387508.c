#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_0033BA68();                            /* extern */

struct func_00387508_arg1 {
    char pad0[0x128];
    s32 unk128;
};
struct func_00387508_arg0 {
    char pad0[0xF09E];
    s8 unkF09E;
};

void func_00387508(struct func_00387508_arg0 *arg0, struct func_00387508_arg1 *arg1) {
    func_0033BA68();
    arg1->unk128 = (s32) (arg0->unkF09E != 0);
}
