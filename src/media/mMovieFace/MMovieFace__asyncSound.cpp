struct Name {
    const char *str;
    Name(const char *s) __asm__("func_0029CF48");
    ~Name() __asm__("func_0029CEF0");
};

extern "C" int func_0029E9F0(const char *s);
extern "C" int D_0057AA10;

extern "C" void MMovieFace__asyncSound(void *self, int count, const char *s) {
    int ok = 1;
    if (count > 0) {
        Name n(s);
        ok = func_0029E9F0(n.str) != 0;
    }
    D_0057AA10 = ok;
}
