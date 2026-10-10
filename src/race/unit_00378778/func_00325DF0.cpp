extern "C" void *func_003216C0(void *arg0);
extern "C" char D_005C9EE8[];

extern "C" void func_00325DF0(void *arg0)
{
    func_003216C0(arg0);
    *(int *)((char *)arg0 + 0x180) = 0;
    *(void **)((char *)arg0 + 0x0) = D_005C9EE8;
}
