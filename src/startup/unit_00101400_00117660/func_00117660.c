#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00117660_arg0 {
    char pad0[0x40008];
    s32 unk40008;
};

void func_00117660(void *arg0) {
    func_004F6678(arg0, 0, 0x40000);
    func_004F6678(arg0 + 0x40000, 0, 8);
    ((struct func_00117660_arg0 *)arg0)->unk40008 = 0;
}
