extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA840(...) throw();
s32 func_004FA860(...) throw();

struct func_004BDEF0_arg0 {
    char pad0[0x34];
    s32 unk34;
    s32 unk38;
};

void func_004BDEF0(char *arg0, s32 arg1) {
    func_004FA860(((struct func_004BDEF0_arg0 *)arg0)->unk38);
    ((struct func_004BDEF0_arg0 *)arg0)->unk34 = (s32) (((struct func_004BDEF0_arg0 *)arg0)->unk34 + arg1);
    func_004FA840(((struct func_004BDEF0_arg0 *)arg0)->unk38);
}

}
