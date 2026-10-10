extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char D_005CFBF0[];

struct func_00358988_arg0 {
    char pad0[0x4];
    void *unk4;
    int unk8;
};

extern "C" void func_00358988(struct func_00358988_arg0 *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    arg0->unk8 = 0;
    arg0->unk4 = D_005CFBF0;
}
