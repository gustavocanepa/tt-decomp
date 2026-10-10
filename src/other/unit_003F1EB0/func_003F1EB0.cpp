extern "C" void *func_003F1C00(void *arg0);
extern "C" char D_005D7950[];

extern "C" void func_003F1EB0(void *arg0)
{
    func_003F1C00(arg0);
    *(int *)((char *)arg0 + 0x28) = 0;
    *(void **)((char *)arg0 + 0x4) = D_005D7950;
}
