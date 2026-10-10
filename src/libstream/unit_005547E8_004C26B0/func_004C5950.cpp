struct Seq {
    char pad[0x58];
    unsigned char *pc;
};

extern "C" long long D_006137B0;
extern "C" void func_005743A0(Seq *s, int c, int a, int b);
extern "C" void func_004C54A0(Seq *s, long long d, int c, int a, int flag);

extern "C" void func_004C5950(Seq *s)
{
    int a = *s->pc++;
    int b = *s->pc++;
    int c = *s->pc++;
    if (b)
        return func_005743A0(s, c, a, b);
    func_004C54A0(s, D_006137B0, c, a, 1);
}
