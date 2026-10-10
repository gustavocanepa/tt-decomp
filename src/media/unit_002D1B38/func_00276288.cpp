extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00276078(...) throw();

struct func_00276288_arg0 {
    char pad0[0x20];
    s32 unk20;
};

s32 func_00276288(char *arg0) {
    if (((struct func_00276288_arg0 *)arg0)->unk20 != 0) {
        func_00276078();
    }
}

}
