struct Ctx { int handle; int pad[3]; };
struct Str { int p; int pad[3]; int get() const { return p; } };
extern "C" void func_00286240(Ctx *c);
extern "C" void func_002861E8(Ctx *c, int flags);
extern "C" void func_001F0C00(Str *s, const char *text);
extern "C" void func_001F0BA8(Str *s, int flags);
extern "C" void func_002868F0(int handle, int str);

extern "C" void func_002864D8(void *self, void *unused, int argc, const char *arg)
{
    if (argc > 0) {
        Ctx c;
        func_00286240(&c);
        Str s;
        func_001F0C00(&s, arg);
        func_002868F0(c.handle, s.get());
        func_001F0BA8(&s, 2);
        func_002861E8(&c, 2);
    }
}
