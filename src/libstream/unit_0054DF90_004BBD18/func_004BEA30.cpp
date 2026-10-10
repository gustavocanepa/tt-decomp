extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F43A8(...) throw();
s32 func_004F43F0(...) throw();
s32 func_004F45D8(...) throw();
s32 func_004F4348(...) throw();

struct func_004BEA30_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
    s32 unk44;
    s32 unk48;
};

void func_004BEA30(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_004F4348(((struct func_004BEA30_arg0 *)arg0)->unk0);
    ((struct func_004BEA30_arg0 *)arg0)->unk40 = arg2;
    ((struct func_004BEA30_arg0 *)arg0)->unk44 = arg3;
    ((struct func_004BEA30_arg0 *)arg0)->unk48 = arg4;
    func_004F43A8(arg3, arg4);
    func_004F45D8(arg0, arg1, 0, 0, 0);
    func_004F43F0(arg3, arg4);
}

}
