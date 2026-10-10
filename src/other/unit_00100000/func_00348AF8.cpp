extern "C" void *func_002CF8E0(void *arg0);
extern "C" char D_005CF020[];

extern "C" void func_00348AF8(void *arg0)
{
    func_002CF8E0(arg0);
    *(void **)((char *)arg0 + 0x4) = D_005CF020;
    *(int *)((char *)arg0 + 0x11E8) = 0;
}
