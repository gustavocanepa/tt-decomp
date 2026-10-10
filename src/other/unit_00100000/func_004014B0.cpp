extern "C" void *func_00400E88(void);
extern "C" void *func_00401FC0(void *arg0);
extern "C" char D_005D9010[];

extern "C" void *func_004014B0(void *arg0)
{
    func_00400E88();
    *(void **)arg0 = D_005D9010;
    return func_00401FC0((char *)arg0 + 0x2B80);
}
