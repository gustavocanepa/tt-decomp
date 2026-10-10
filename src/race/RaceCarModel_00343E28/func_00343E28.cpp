extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00388F30(...) throw();
s32 func_0041A4C8(...) throw();
s32 func_0041A4E8(...) throw();

void func_00343E28(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_0041A4C8(arg0 + 0x18);
        return;
    }
    func_0041A4E8(arg0 + 0x18);
    func_00388F30(0);
}

}
