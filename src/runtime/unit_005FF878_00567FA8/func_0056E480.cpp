extern "C" void *func_004AC758(void *arg0);
extern "C" char D_005DA5E0[];

struct func_0056E480_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_0056E480(struct func_0056E480_arg0 *arg0)
{
    func_004AC758(arg0);
    arg0->unk8 = D_005DA5E0;
}
