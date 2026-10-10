extern "C" void *func_004ACA80(void *arg0);
extern "C" char D_005A49C0[];

struct func_0050EFA8_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_0050EFA8(struct func_0050EFA8_arg0 *arg0)
{
    func_004ACA80(arg0);
    arg0->unk8 = D_005A49C0;
}
