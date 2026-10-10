typedef int s32;

struct Obj {
    char pad0[0x18];
    void *unk18;
    char unk1C[1];
};

extern void *D_005DB6D8;
extern "C" void func_004AE9F0(void *, s32);
extern "C" void func_004F4868(void *, s32);
extern "C" void func_0050E1A8(void *);

extern "C" void func_004F4C30(struct Obj *arg0, s32 arg1)
{
    arg0->unk18 = &D_005DB6D8;
    func_004AE9F0(&arg0->unk1C, 2);
    func_004F4868(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
