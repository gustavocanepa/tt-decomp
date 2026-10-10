extern "C" void *func_002CE060(void *arg0);
extern "C" char D_005D4D28[];

extern "C" void func_00385BC8(void *arg0)
{
    func_002CE060(arg0);
    *(int *)((char *)arg0 + 0x58) = 0;
    *(int *)((char *)arg0 + 0x54) = 0;
    *(void **)((char *)arg0 + 0x20) = D_005D4D28;
}
