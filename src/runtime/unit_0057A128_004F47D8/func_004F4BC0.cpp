extern "C" void *func_004F47D8(void);
extern "C" void *func_004AE9C0(void *arg0);
extern "C" char D_005DB6D8[];

extern "C" void *func_004F4BC0(void *arg0)
{
    func_004F47D8();
    *(void **)((char *)arg0 + 0x18) = D_005DB6D8;
    return func_004AE9C0((char *)arg0 + 0x1C);
}
