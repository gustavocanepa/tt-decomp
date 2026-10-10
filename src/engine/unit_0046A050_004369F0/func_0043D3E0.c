#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0043D4C0(void *);                      /* extern */
s32 func_0043D510();                            /* extern */

struct func_0043D3E0_arg1 {
    s32 unk0;
    s32 unk4;
};
struct func_0043D3E0_arg0 {
    s32 unk0;
    s32 unk4;
};

void *func_0043D3E0(struct func_0043D3E0_arg0 *arg0, struct func_0043D3E0_arg1 *arg1) {
    s32 temp_s1;

    temp_s1 = arg1->unk0;
    func_0043D510();
    arg0->unk0 = temp_s1;
    arg0->unk4 = (s32) arg1->unk4;
    func_0043D4C0(arg0);
    return arg0;
}
