extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046F0F8(...) throw();
s32 func_0046F498(...) throw();
s32 func_00478C98(...) throw();

void func_00439E80(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        func_0046F0F8(0xF);
        func_0046F498(arg2 != 0);
        return;
    }
    func_00478C98(0xF);
}

}
