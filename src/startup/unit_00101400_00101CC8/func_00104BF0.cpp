extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046E3D0(...) throw();
s32 func_0046E638(...) throw();
s32 func_0046E6D0(...) throw();

struct func_00104BF0_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    char pad20[0x10];
    s32 unk30;
};

void func_00104BF0(char *arg0) {
    if (((struct func_00104BF0_arg0 *)arg0)->unk30 != 0) {
        func_0046E638(((struct func_00104BF0_arg0 *)arg0)->unk10, ((struct func_00104BF0_arg0 *)arg0)->unk14, ((struct func_00104BF0_arg0 *)arg0)->unk18, ((struct func_00104BF0_arg0 *)arg0)->unk1C);
        func_0046E6D0(((struct func_00104BF0_arg0 *)arg0)->unk0, ((struct func_00104BF0_arg0 *)arg0)->unk4, ((struct func_00104BF0_arg0 *)arg0)->unk8, ((struct func_00104BF0_arg0 *)arg0)->unkC);
        return;
    }
    func_0046E3D0(0);
}

}
