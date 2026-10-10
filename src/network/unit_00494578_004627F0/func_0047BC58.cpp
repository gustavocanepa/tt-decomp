struct Name {
    int data;
    Name(const Name &o);
};

extern "C" unsigned int func_004A8368(const char *s);
extern "C" void func_0047A730(char *dst, const char *src);
extern "C" Name func_0047BAB8(void *ctx, int flag, const char *s);

extern "C" Name func_0047BC58(void *ctx, const char *s) {
    char *buf = (char *)__builtin_alloca(func_004A8368(s) + 1);
    func_0047A730(buf, s);
    return func_0047BAB8(ctx, 1, buf);
}
