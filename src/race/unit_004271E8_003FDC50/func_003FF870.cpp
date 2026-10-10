extern "C" void *func_00400D68(void);
extern "C" void *func_003FF910(void *arg0);
extern "C" char D_005D8E78[];

extern "C" void *func_003FF870(void *arg0)
{
    func_00400D68();
    *(void **)arg0 = D_005D8E78;
    return func_003FF910(arg0);
}
