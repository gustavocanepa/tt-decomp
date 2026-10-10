extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C70A0(...) throw();
s32 func_004C8310(...) throw();

struct func_004C82A0_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x10];
    u8 unk1C;
    char pad1D[0x13];
    s32 unk30;
};

void func_004C82A0(char *arg0, s32 arg1) {
    func_004C70A0(((struct func_004C82A0_arg0 *)arg0)->unk8, arg0, arg1 == 0);
    if (((struct func_004C82A0_arg0 *)arg0)->unk1C != 0) {
        func_004C8310(arg0, ((struct func_004C82A0_arg0 *)arg0)->unk30);
        return;
    }
    func_004C8310(arg0, arg1);
}

}
