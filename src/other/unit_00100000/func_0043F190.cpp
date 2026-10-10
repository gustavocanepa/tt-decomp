extern "C" float func_0043E0B0(void *v);
extern "C" void func_0043D810(void *v, int i);

extern "C" void func_0043F190(void *a, void *b)
{
    float x = func_0043E0B0(a);
    func_0043D810(a, (int)x | (int)func_0043E0B0(b));
}
