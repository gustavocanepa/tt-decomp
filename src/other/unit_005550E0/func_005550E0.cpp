typedef int s32;

struct S { char pad[0x8]; void *unk8; };

extern void func_0050E1A8(S *);
extern char D_005CE900;

void func_005550E0(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unk8 = &D_005CE900;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
