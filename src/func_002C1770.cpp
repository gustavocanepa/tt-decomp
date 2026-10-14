/* compiler: ee-gcc2.96-no-strict-aliasing */
struct String { char *data; };
extern char D_005F2390[];
extern "C" double func_004B4C18(float);
extern "C" void func_004A6500(char *, const char *, ...);
extern "C" int func_004A8368(const char *) throw();
extern "C" void *func_0050F1B0(void *, unsigned int, unsigned int, const char *, unsigned int);
static inline void format(char *buf, const char *fmt, double value) {
    func_004A6500(buf, fmt, value);
}
extern "C" String *func_002C1770(String *self, float value) {
    char buf[32];
    format(buf, D_005F2390, func_004B4C18(value));
    unsigned int n = func_004A8368(buf);
    func_0050F1B0(self, ((unsigned int *)self->data)[-4], 0, buf, n);
    return self;
}
