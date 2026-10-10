extern "C" void *func_0045E950(void *mgr, const char *name);
extern "C" void func_0045EA18(void *player, void *item);
extern "C" void *D_00586EF4;
extern "C" void *D_00586EF8;

extern "C" void func_0045E010(const char *name)
{
    if (!name || !D_00586EF4)
        return;
    void *item = func_0045E950(D_00586EF4, name);
    if (D_00586EF8 && item)
        func_0045EA18(D_00586EF8, item);
}
