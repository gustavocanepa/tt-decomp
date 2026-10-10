extern "C" void *func_00400D68(void);
extern "C" void *func_00400158(void *arg0);
extern "C" char D_005D8EF8[];

extern "C" void *func_004000B8(void *arg0)
{
    func_00400D68();
    *(void **)arg0 = D_005D8EF8;
    return func_00400158(arg0);
}
