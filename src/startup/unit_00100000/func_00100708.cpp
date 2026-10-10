extern "C" void *func_00108678(void *arg0);
extern "C" char D_005A49A8[];

struct func_00100708_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_00100708(struct func_00100708_arg0 *arg0)
{
    func_00108678(arg0);
    arg0->unk8 = D_005A49A8;
}
