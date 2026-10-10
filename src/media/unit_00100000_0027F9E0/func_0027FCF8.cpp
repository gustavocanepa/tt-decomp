extern "C" void *func_002A7618(void);
extern "C" void *func_0026CFC0(void *arg0);
extern "C" char D_005C1398[];

extern "C" void *func_0027FCF8(void *arg0)
{
    func_002A7618();
    *(void **)((char *)arg0 + 4) = D_005C1398;
    return func_0026CFC0((char *)arg0 + 0x10);
}
