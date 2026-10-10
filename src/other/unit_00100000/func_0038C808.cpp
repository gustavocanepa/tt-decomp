extern "C" void *func_0034F6E8(void *arg0);
extern "C" void *func_00359690(char *arg0);
extern "C" char D_005D5958[];

extern "C" void *func_0038C808(void *arg0)
{
    void *s0 = arg0;
    func_0034F6E8(s0);
    *(void **)((char *)s0 + 0x0) = D_005D5958;
    return func_00359690((char *)s0 + 0x54BC);
}
