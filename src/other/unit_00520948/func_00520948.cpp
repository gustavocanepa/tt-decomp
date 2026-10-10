extern "C" void *func_0019B420(void *arg0);
extern "C" char D_005AD1E0[];

struct S00415470 {
    char pad[0x4C];
    void *unk4C;
};

extern "C" void func_00520948(S00415470 *arg0)
{
    func_0019B420(arg0);
    arg0->unk4C = D_005AD1E0;
}
