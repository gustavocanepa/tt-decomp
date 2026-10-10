extern "C" void *func_001B1790(void *arg0);
extern "C" char D_005AFBF8[];

struct func_001CF6F8_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x20];
    int unk28;
};

extern "C" void func_001CF6F8(struct func_001CF6F8_arg0 *arg0)
{
    func_001B1790(arg0);
    arg0->unk28 = 0;
    arg0->unk4 = D_005AFBF8;
}
