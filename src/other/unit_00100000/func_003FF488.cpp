extern "C" void *func_00400D68(void);
extern "C" void *func_003FF528(void *arg0);
extern "C" char D_005D8E38[];

extern "C" void *func_003FF488(void *arg0)
{
    func_00400D68();
    *(void **)arg0 = D_005D8E38;
    return func_003FF528(arg0);
}
