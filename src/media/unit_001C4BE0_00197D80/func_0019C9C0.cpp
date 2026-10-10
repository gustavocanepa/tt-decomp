extern "C" const char *func_0019BD98(void);
extern "C" char *func_004F7B74(char *dst, const char *src);
extern "C" int func_004A8368(const char *s);

extern "C" void func_0019C9C0(char *buf, int c)
{
    char *name = buf + 1;
    buf[0] = '/';
    func_004F7B74(name, func_0019BD98());
    buf += func_004A8368(name) + 1;
    if (c > 0)
        *buf++ = c;
    buf[0] = '*';
    buf[1] = 0;
}
