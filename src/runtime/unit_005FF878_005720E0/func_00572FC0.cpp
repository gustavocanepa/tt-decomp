extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_004F43A8(...) throw();

struct func_00572FC0_arg0 {
    char pad0[0x88];
    s32 unk88;
    s32 unk8C;
};

s32 func_00572FC0(char *arg0, s32 *arg1, s32 *arg2) {
    func_004F43A8(arg0 + 0x80, 0x40);
    *arg1 = ((struct func_00572FC0_arg0 *)arg0)->unk88;
    *arg2 = ((struct func_00572FC0_arg0 *)arg0)->unk8C;
}

}
