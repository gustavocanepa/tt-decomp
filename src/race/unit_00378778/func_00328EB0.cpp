extern "C" void *func_003216C0(void *arg0);
extern "C" char D_005CA738[];

struct func_00328EB0_arg0 {
    void *unk0;
    char pad4[0x17C];
    int unk180;
};

extern "C" void func_00328EB0(struct func_00328EB0_arg0 *arg0)
{
    func_003216C0(arg0);
    arg0->unk180 = 0;
    arg0->unk0 = D_005CA738;
}
