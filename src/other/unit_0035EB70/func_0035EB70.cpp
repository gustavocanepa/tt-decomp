extern "C" void *func_003595B0(void *arg0);
extern "C" char D_005D0C70[];

extern "C" void func_0035EB70(void *arg0)
{
    func_003595B0(arg0);
    *(int *)((char *)arg0 + 0x68) = 0;
    *(void **)((char *)arg0 + 0x14) = D_005D0C70;
}
