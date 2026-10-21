/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004A8368(const char *s) throw();

extern "C" unsigned long func_00418938(const char *s) {
    int n = func_004A8368(s);
    unsigned long t = 0;
    int i;
    for (i = 0; i < n; i++)
        t += (unsigned char)s[i];
    unsigned long h = t & 0xFFFF;
    for (i = 0; i < n; i++) {
        unsigned char c = s[i];
        t = h >> 57;
        h <<= 7;
        h |= t;
        h += c;
    }
    return h;
}
