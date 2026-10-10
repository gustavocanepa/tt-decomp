extern "C" void *func_002A7618(void);
extern "C" void *func_0040EB38(void *arg0);
extern "C" char D_005A9D40[];

extern "C" void *func_00184888(void *arg0)
{
    func_002A7618();
    *(void **)((char *)arg0 + 4) = D_005A9D40;
    return func_0040EB38((char *)arg0 + 0x10);
}
