/* compiler: ee-gcc2.96-no-strict-aliasing */
#define CT(c) (((unsigned char *)0x616779)[c])
extern "C" unsigned int func_004A8368(const char *s) throw();
extern "C" void func_004F7A30(char *d, const char *s);

extern "C" void func_002AAC88(char *dst, const char *dir, const char *file) {
    const char *p = dir;
    const char *dp;
    char *out;
    char c;
    char c2;
    if (CT(*p) & 3) {
        p++;
        while (c = *p, (CT(c) & 7) && c != 0)
            p++;
        p = c == ':' ? p + 1 : dir;
    }
    dp = p;
    p = file;
    if (CT(*p) & 3) {
        p++;
        while (c2 = *p, (CT(c2) & 7) && c2 != 0)
            p++;
        p = c2 == ':' ? p + 1 : file;
    }
    out = dst;
    *out = 0;
    if (*p != '/') {
        func_004F7A30(dst, dir);
        out += func_004A8368(dir);
        if (*dp != 0) {
            *out = '/';
            out++;
        }
        *out = 0;
    }
    func_004F7A30(out, p);
}
