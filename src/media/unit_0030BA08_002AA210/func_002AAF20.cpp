extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F7B74(...) throw();
s32 func_004F87D0(...) throw();

void func_002AAF20(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_004F87D0(arg1, 0x2F);
    if (temp_v0 != 0) {
        func_004F7B74(arg0, temp_v0 + 1);
        return;
    }
    func_004F7B74(arg0, arg1);
}

}
