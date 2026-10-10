extern "C" void *RaceBGMPS2__structor_0(void *arg0);
extern "C" char D_005D2C98[];

extern "C" void func_00370E40(void *arg0)
{
    RaceBGMPS2__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = D_005D2C98;
    *(int *)((char *)arg0 + 0x11E8) = 0;
}
