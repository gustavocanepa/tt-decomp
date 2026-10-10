extern "C" void *func_003DDF18(void *arg0);
extern "C" char D_005D7318[];

struct S00415470 {
    char pad[0x4C];
    void *unk4C;
};

extern "C" void func_003DDFE8(S00415470 *arg0)
{
    func_003DDF18(arg0);
    arg0->unk4C = D_005D7318;
}
