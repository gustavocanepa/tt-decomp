struct Name { const char *str; int pad[3]; };

extern "C" void func_0029CF48(Name *self, const char *s);
extern "C" void func_0029CEF0(Name *self, int flags);
extern "C" int func_0029E9F0(const char *s);
extern "C" void func_001B2FE8(void *target, int on);
extern "C" char D_0057A938[];

extern "C" void func_001D0578(void *self, int argc, const char *arg)
{
    int on = 1;
    if (argc > 0) {
        Name n;
        func_0029CF48(&n, arg);
        on = func_0029E9F0(n.str) != 0;
        func_0029CEF0(&n, 2);
    }
    func_001B2FE8(D_0057A938, on);
}
