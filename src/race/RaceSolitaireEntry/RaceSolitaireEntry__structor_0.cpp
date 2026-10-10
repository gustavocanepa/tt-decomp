extern "C" void *func_002CE060(void *arg0);
extern "C" char D_005D4D28[];

struct RaceSolitaireEntry__structor_0_arg0 {
    char pad0[0x20];
    void *unk20;
    char pad24[0x30];
    int unk54;
    int unk58;
};

extern "C" void RaceSolitaireEntry__structor_0(struct RaceSolitaireEntry__structor_0_arg0 *arg0)
{
    func_002CE060(arg0);
    arg0->unk58 = 0;
    arg0->unk54 = 0;
    arg0->unk20 = D_005D4D28;
}
