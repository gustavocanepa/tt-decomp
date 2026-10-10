extern "C" void *func_0050EFA8(void *arg0);
extern "C" char D_005A4DC8[];

struct func_00108678_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_00108678(struct func_00108678_arg0 *arg0)
{
    func_0050EFA8(arg0);
    arg0->unk8 = D_005A4DC8;
}
