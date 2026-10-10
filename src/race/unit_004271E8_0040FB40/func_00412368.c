#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */

struct func_00412368_arg0 {
    s64 unk0;
    s32 unk8;
    s32 unkC;
};

void func_00412368(struct func_00412368_arg0 *arg0) {
    arg0->unk0 = -1;
    func_004A45D0(arg0->unk8);
    arg0->unk8 = 0;
    arg0->unkC = 0;
}
