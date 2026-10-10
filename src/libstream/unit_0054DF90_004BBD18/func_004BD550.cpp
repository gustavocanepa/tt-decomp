extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(...) throw();

struct func_004BD550_arg0 {
    char pad0[0x4];
    char *unk4;
    char *unk8;
    char *unkC;
};

void func_004BD550(char *arg0) {
    func_004A45D0(((struct func_004BD550_arg0 *)arg0)->unkC);
    func_004A45D0(((struct func_004BD550_arg0 *)arg0)->unk8);
    func_004A45D0(((struct func_004BD550_arg0 *)arg0)->unk4);
    func_004A45D0(arg0);
}

}
