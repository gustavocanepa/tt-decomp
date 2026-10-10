extern "C" void *func_00358988(void *arg0);
extern "C" char D_005CFBC8[];

extern "C" void func_00358A60(void *arg0)
{
    func_00358988(arg0);
    *(void **)((char *)arg0 + 0x4) = D_005CFBC8;
    *(int *)((char *)arg0 + 0xC) = 0;
}
