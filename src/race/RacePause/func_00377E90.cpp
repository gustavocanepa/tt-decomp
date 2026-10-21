#include "types.h"

struct S { char pad[0x8]; void *unk8; };

extern void func_0050E1A8(S *);
extern char D_005D3AC0;

void func_00377E90(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unk8 = &D_005D3AC0;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
