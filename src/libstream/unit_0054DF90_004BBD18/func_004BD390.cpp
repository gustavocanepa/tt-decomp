struct Thread64 {
    int sema;
    char pad4[0x3C];
    long long arg0;
    long long arg1;
};

extern Thread64 D_00776C80;
extern "C" void func_004F4348(int sema);
extern "C" void func_004F45D8(Thread64 *t, int a, int b, int c, int d);

extern "C" void func_004BD390(long long arg0, long long arg1)
{
    Thread64 *t = &D_00776C80;
    func_004F4348(t->sema);
    t->arg0 = arg0;
    t->arg1 = arg1;
    func_004F45D8(t, 0x3, 1, 0, 0);
}
