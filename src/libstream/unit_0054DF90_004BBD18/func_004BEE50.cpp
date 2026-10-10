struct Thread {
    int sema;
    char pad4[0x3C];
    int arg0;
    int arg1;
};

extern Thread D_00776D80;
extern "C" void func_004F4348(int sema);
extern "C" void func_004F45D8(Thread *t, int a, int b, int c, int d);

extern "C" void func_004BEE50(int arg0, int arg1)
{
    Thread *t = &D_00776D80;
    func_004F4348(t->sema);
    t->arg0 = arg0;
    t->arg1 = arg1;
    func_004F45D8(t, 0x9, 0, 0, 0);
}
