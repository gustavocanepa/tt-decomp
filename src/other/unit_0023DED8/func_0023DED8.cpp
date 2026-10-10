extern "C" void *func_002A7618(void);
extern "C" void *func_0045D898(void *arg0);
extern "C" char D_005B9C30[];

extern "C" void *func_0023DED8(void *arg0)
{
    func_002A7618();
    *(void **)((char *)arg0 + 4) = D_005B9C30;
    return func_0045D898((char *)arg0 + 0x10);
}
