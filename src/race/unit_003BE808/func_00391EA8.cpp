extern "C" void *RaceMeterBase__structor_1(void *arg0);
extern "C" char D_005D5BC0[];

struct func_00391EA8_arg0 {
    char pad0[0x14];
    void *unk14;
};

extern "C" void func_00391EA8(struct func_00391EA8_arg0 *arg0)
{
    RaceMeterBase__structor_1(arg0);
    arg0->unk14 = D_005D5BC0;
}
