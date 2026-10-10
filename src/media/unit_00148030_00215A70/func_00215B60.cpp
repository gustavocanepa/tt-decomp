extern "C" void *func_001CE6A8(void *arg0);
extern "C" char D_005B3FC0[];

struct func_00215B60_arg0 {
    char pad0[0x4];
    void *unk4;
    int unk8;
    int unkC;
};

extern "C" void func_00215B60(struct func_00215B60_arg0 *arg0)
{
    func_001CE6A8(arg0);
    arg0->unkC = 0;
    arg0->unk8 = 0;
    arg0->unk4 = D_005B3FC0;
}
