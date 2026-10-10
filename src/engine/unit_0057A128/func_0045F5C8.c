#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0045F5C8_arg0 {
    char pad0[0x54];
    f32 unk54;
    f32 unk58;
};

void func_0045F5C8(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    func_0045FE50(arg0, arg3, 0, 0, 1);
    *arg1 = ((struct func_0045F5C8_arg0 *)arg0)->unk54;
    *arg2 = ((struct func_0045F5C8_arg0 *)arg0)->unk58;
}
