struct Buf { char *p; unsigned n; };
extern "C" int func_00414D60(Buf *);
extern "C" int func_00415080(Buf *);
extern "C" void func_00415168(char *, char *);
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" void *func_004F6678(void *, int, unsigned);

extern "C" unsigned func_004151A0(char *out, unsigned size, const void *src, unsigned n, int fill) {
    Buf b;
    unsigned i;
    unsigned cnt;
    b.p = (char *)__builtin_alloca(n);
    b.n = n;
    i = 0;
    func_004F64C4(b.p, src, n);
    for (cnt = 0; func_00414D60(&b) == 0; ) {
        cnt++;
        out[i++] = func_00415080(&b) + '0';
        if (i >= size) i = 0;
    }
    char *p = out + i;
    if (size < cnt) {
        func_00415168(out, p - 1);
        func_00415168(p, out + size - 1);
    } else if (fill >= 0) {
        func_004F6678(out + cnt, fill, size - cnt);
        func_00415168(out, out + size - 1);
        cnt = size;
    } else {
        func_00415168(out, out + cnt - 1);
    }
    return cnt;
}
