/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004A8368(const char *);
extern "C" char *func_004F7A30(char *, const char *);
extern "C" void func_004A87A0(char *, int, int, int, int, int);
extern "C" void func_004A8970(const char *dir, const char *name, const char *ext, int a, int b, int c, int d, int e) {
    int len = func_004A8368(name) + 1;
    if (dir != 0) len += func_004A8368(dir);
    if (ext != 0) len += func_004A8368(ext);
    char *buf = (char *)__builtin_alloca((len + 15) & ~15);
    buf[0] = 0;
    if (dir != 0) func_004F7A30(buf, dir);
    func_004F7A30(buf, name);
    if (ext != 0) func_004F7A30(buf, ext);
    func_004A87A0(buf, a, b, c, d, e);
}
