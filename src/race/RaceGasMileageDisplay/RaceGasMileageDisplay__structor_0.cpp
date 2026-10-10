extern "C" void *RaceValueDisplayBase__structor_1(void *arg0);
extern "C" char D_005D0C70[];

struct RaceGasMileageDisplay__structor_0_arg0 {
    char pad0[0x14];
    void *unk14;
    char pad18[0x50];
    int unk68;
};

extern "C" void RaceGasMileageDisplay__structor_0(struct RaceGasMileageDisplay__structor_0_arg0 *arg0)
{
    RaceValueDisplayBase__structor_1(arg0);
    arg0->unk68 = 0;
    arg0->unk14 = D_005D0C70;
}
