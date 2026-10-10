extern "C" void *func_0022C018(void *arg0);
extern "C" char D_005B89E8[];

struct func_002345D8_arg0 {
    char pad0[0x4];
    void *unk4;
    int unk8;
};

extern "C" void func_002345D8(struct func_002345D8_arg0 *arg0)
{
    func_0022C018(arg0);
    arg0->unk8 = 0;
    arg0->unk4 = D_005B89E8;
}
