extern "C" char D_005F0FD0[];

struct Rep {
    unsigned int len;
    unsigned int res;
    unsigned int ref;
    int selfish;
};
struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    unsigned int length() const { return rep()->len; }
    const char *c_str() const
    {
        if (length() == 0)
            return D_005F0FD0;
        p[length()] = 0;
        return p;
    }
};
extern "C" int func_0029F6F8(void);
extern "C" void func_0054A940(Str *s, int n, int c);
extern "C" void func_0029F6A0(void *ret, const char *s, int n);

extern "C" void *func_0029F8F8(void *ret, Str *s)
{
    int n = func_0029F6F8();
    func_0054A940(s, n, 0);
    func_0029F6A0(ret, s->c_str(), n);
    return ret;
}
