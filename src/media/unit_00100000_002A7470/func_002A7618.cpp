extern "C" void *func_002C0EB0(void *arg0);
extern "C" char D_005C5A10[];

struct func_002A7618_arg0 {
    char pad0[0x4];
    void *unk4;
    int unk8;
    int unkC;
};

extern "C" void func_002A7618(struct func_002A7618_arg0 *arg0)
{
    func_002C0EB0(arg0);
    arg0->unkC = 0;
    arg0->unk8 = 0;
    arg0->unk4 = D_005C5A10;
}
