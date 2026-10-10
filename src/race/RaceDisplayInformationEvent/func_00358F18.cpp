extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char D_005CFAB0[];

extern "C" void func_00358F18(void *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = D_005CFAB0;
}
