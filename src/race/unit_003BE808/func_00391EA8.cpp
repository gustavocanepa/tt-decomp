extern "C" void *RaceMeterBase__structor_1(void *arg0);
extern "C" char D_005D5BC0[];

extern "C" void func_00391EA8(void *arg0)
{
    RaceMeterBase__structor_1(arg0);
    *(void **)((char *)arg0 + 0x14) = D_005D5BC0;
}
