struct Iter { int w[4]; };
struct Info { int count; };
extern "C" Info *func_004369F0(void *, int);
extern "C" void func_004368A8(Iter *, void *, int);
extern "C" char *func_00436968(Iter *, int);
extern "C" void *func_004F6678(void *, int, unsigned int);

extern "C" int func_00438888(void *t)
{
    if (!func_004369F0(t, 5)) return 0;
    Iter it;
    func_004368A8(&it, t, 5);
    for (int i = 0; i < func_004369F0(t, 5)->count; i++)
        func_004F6678(func_00436968(&it, i) + 0x38, 0, 8);
    return 1;
}
