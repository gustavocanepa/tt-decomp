extern "C" void *func_003216C0(void *arg0);
extern "C" char D_005CAB40[];

struct func_0032C038_arg0 {
    void *unk0;
    char pad4[0x17C];
    int unk180;
};

extern "C" void func_0032C038(struct func_0032C038_arg0 *arg0)
{
    func_003216C0(arg0);
    arg0->unk180 = 0;
    arg0->unk0 = D_005CAB40;
}
