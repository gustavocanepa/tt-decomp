struct Stats { int a, b, c, d, e, f; };
extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);
extern "C" char D_005A0B88[];

extern "C" void func_004C4218(Stats *s)
{
    func_004A4930(D_005A0B88);
    s->a = 0;
    s->b = 0;
    s->e = 0;
    s->f = 0;
    s->c = 0;
    s->d = 0;
    func_004A4970(D_005A0B88);
}
