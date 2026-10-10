extern "C" void *func_001B1790(void *arg0);
extern "C" char D_005AFBF8[];

extern "C" void func_001CF6F8(void *arg0)
{
    func_001B1790(arg0);
    *(int *)((char *)arg0 + 0x28) = 0;
    *(void **)((char *)arg0 + 0x4) = D_005AFBF8;
}
