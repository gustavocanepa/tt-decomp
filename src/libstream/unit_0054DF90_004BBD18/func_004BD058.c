/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef unsigned long long u64;
typedef struct { u64 v; } __attribute__((packed)) U64;

static inline void copy8(U64 *d, const U64 *s) { d->v = s->v; }

void func_004BD058(void *dst, const void *src, unsigned int n) {
    U64 *d = dst;
    const U64 *s = src;
    U64 *e = d + (n >> 3);
    char *dc;
    const char *sc;
    char *ec;

    while (d != e) {
        __asm__ volatile("pref 0, 64(%0)" : : "r"(s));
        copy8(d++, s++);
    }
    dc = (char *)d;
    sc = (const char *)s;
    ec = dc + (n & 7);
    while (dc != ec) *dc++ = *sc++;
}
