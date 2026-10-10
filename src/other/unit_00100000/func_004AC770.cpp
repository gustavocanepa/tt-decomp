typedef int s32;

struct S { char pad[0x8]; void *unk8; };

extern void func_0050E1A8(S *);
extern char D_005DADE0;

void func_004AC770(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unk8 = &D_005DADE0;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
