extern "C" void *func_002A7618(void);
extern "C" void *func_004CAFB8(void *arg0);
extern "C" char D_005B0238[];

extern "C" void *func_001D3728(void *arg0)
{
    func_002A7618();
    *(void **)((char *)arg0 + 4) = D_005B0238;
    return func_004CAFB8((char *)arg0 + 0x10);
}
