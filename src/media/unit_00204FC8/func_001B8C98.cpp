struct Ctx { int handle; int pad[3]; };
struct Str { int p; int pad[3]; int get() const { return p; } };
extern "C" void func_001B7F98(Ctx *c);
extern "C" void func_001B7F40(Ctx *c, int flags);
extern "C" void func_002027E0(Str *s, const char *text);
extern "C" void func_00202788(Str *s, int flags);
extern "C" void func_001B92A0(int handle, int str);

extern "C" void func_001B8C98(void *self, void *unused, int argc, const char *arg)
{
    if (argc > 0) {
        Ctx c;
        func_001B7F98(&c);
        Str s;
        func_002027E0(&s, arg);
        func_001B92A0(c.handle, s.get());
        func_00202788(&s, 2);
        func_001B7F40(&c, 2);
    }
}
