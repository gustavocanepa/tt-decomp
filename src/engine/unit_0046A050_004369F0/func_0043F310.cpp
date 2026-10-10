extern "C" float func_0043E0B0(void *);
extern "C" void func_0043D810(void *, unsigned int);

extern "C" void func_0043F310(void *a, void *b)
{
    float x = func_0043E0B0(a);
    float y = func_0043E0B0(b);
    func_0043D810(a, (unsigned int)x >> (int)y);
}
