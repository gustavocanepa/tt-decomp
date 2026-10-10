extern "C" void *func_00400D68(void *arg0);
extern "C" void *func_00412908(char *arg0);
extern "C" char D_005D9420[];

extern "C" void *func_004026C8(void *arg0)
{
    void *s0 = arg0;
    func_00400D68(s0);
    *(void **)((char *)s0 + 0x0) = D_005D9420;
    return func_00412908((char *)s0 + 0x4);
}
