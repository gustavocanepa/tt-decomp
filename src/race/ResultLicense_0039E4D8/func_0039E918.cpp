extern "C" void *func_00391EA8(void *arg0);
extern "C" char D_005D5DC0[];

struct func_0039E918_arg0 {
    char pad0[0x14];
    void *unk14;
};

extern "C" void func_0039E918(struct func_0039E918_arg0 *arg0)
{
    func_00391EA8(arg0);
    arg0->unk14 = D_005D5DC0;
}
