extern "C" void *func_002A7618(void);
extern "C" void *func_004026C8(void *arg0);
extern "C" char D_005A8818[];

extern "C" void *func_0016B940(void *arg0)
{
    func_002A7618();
    *(void **)((char *)arg0 + 4) = D_005A8818;
    return func_004026C8((char *)arg0 + 0x10);
}
