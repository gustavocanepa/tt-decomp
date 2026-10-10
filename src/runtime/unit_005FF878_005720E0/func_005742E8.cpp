struct Timer { char pad[0x4C]; float total; };
extern "C" unsigned long long func_004C5208(Timer *t);

extern "C" void func_005742E8(Timer *t)
{
    t->total += func_004C5208(t);
}
