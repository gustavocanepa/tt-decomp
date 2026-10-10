extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char D_005CFB00[];

extern "C" void func_00358D38(void *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = D_005CFB00;
}
