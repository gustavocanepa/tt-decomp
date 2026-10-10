struct Thread {
    int sema;
    char pad4[0x7C];
    int arg0;
    int arg1;
};

extern Thread D_00774100;
extern "C" void func_004F4348(int sema);
extern "C" void func_004F45D8(Thread *t, int a, int b, int c, int d);

extern "C" void func_004B62F8(int arg0, int arg1)
{
    Thread *t = &D_00774100;
    func_004F4348(t->sema);
    t->arg0 = arg0;
    t->arg1 = arg1;
    func_004F45D8(t, 2, 1, 0, 0);
}
