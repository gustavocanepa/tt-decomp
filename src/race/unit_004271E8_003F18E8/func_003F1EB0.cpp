extern "C" void *func_003F1C00(void *arg0);
extern "C" char D_005D7950[];

struct func_003F1EB0_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x20];
    int unk28;
};

extern "C" void func_003F1EB0(struct func_003F1EB0_arg0 *arg0)
{
    func_003F1C00(arg0);
    arg0->unk28 = 0;
    arg0->unk4 = D_005D7950;
}
