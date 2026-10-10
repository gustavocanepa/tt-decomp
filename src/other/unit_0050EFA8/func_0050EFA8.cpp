extern "C" void *func_004ACA80(void *arg0);
extern "C" char D_005A49C0[];

extern "C" void func_0050EFA8(void *arg0)
{
    func_004ACA80(arg0);
    *(void **)((char *)arg0 + 8) = D_005A49C0;
}
