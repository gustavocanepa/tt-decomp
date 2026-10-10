extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FE748(...) throw();
s32 func_003FE7B0(...) throw();

struct func_003FE710_arg0 {
    char pad0[0x6];
    u8 unk6;
};

void func_003FE710(char *arg0) {
    if (((struct func_003FE710_arg0 *)arg0)->unk6 == 0) {
        func_003FE748();
        return;
    }
    func_003FE7B0();
}

}
