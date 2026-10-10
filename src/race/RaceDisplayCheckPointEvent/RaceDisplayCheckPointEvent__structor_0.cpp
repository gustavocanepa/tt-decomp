extern "C" void *func_00358988(void *arg0);
extern "C" char D_005CFBC8[];

struct RaceDisplayCheckPointEvent__structor_0_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x4];
    int unkC;
};

extern "C" void RaceDisplayCheckPointEvent__structor_0(struct RaceDisplayCheckPointEvent__structor_0_arg0 *arg0)
{
    func_00358988(arg0);
    arg0->unk4 = D_005CFBC8;
    arg0->unkC = 0;
}
