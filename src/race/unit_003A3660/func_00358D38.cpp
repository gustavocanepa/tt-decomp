extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char D_005CFB00[];

struct func_00358D38_arg0 {
    char pad0[0x4];
    void *unk4;
    int unk8;
};

extern "C" void func_00358D38(struct func_00358D38_arg0 *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    arg0->unk8 = 0;
    arg0->unk4 = D_005CFB00;
}
