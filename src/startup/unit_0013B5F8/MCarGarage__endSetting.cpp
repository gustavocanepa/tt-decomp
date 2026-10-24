#include "types.h"

struct Buf0013FF38 {
    void *unk0;
    char pad[0xC];
};

extern "C" void func_00128470(struct Buf0013FF38 *arg0);
extern "C" s32 func_001324D8(void *arg0);
extern "C" void func_00408CD0(s32 arg0);
extern "C" void func_00128418(struct Buf0013FF38 *arg0, s32 arg1);

extern "C" void MCarGarage__endSetting(void)
{
    struct Buf0013FF38 buf;

    func_00128470(&buf);
    func_00408CD0(func_001324D8(buf.unk0));
    func_00128418(&buf, 2);
}
