extern "C" void *func_00359CD8(void *arg0);
extern "C" char D_005D0230[];

extern "C" void func_00363788(void *arg0)
{
    func_00359CD8(arg0);
    *(int *)((char *)arg0 + 0x154) = 0;
    *(int *)((char *)arg0 + 0x150) = 0;
    *(void **)((char *)arg0 + 0x14) = D_005D0230;
}
