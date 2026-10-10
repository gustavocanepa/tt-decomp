struct Tmp { int w[4]; };
struct Id { unsigned char b[8]; };
extern "C" int func_004B65E8(void *);
extern "C" void func_004AF960(Tmp *, int);
extern "C" Id func_004B7118(Tmp *);

extern "C" int func_004B7048(Id *out)
{
    Tmp t;
    func_004AF960(&t, func_004B65E8(out));
    Id r = func_004B7118(&t);
    *out = r;
    return 0;
}
