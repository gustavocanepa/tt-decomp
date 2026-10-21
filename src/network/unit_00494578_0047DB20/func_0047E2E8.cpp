/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" const signed char *func_0047E188(const signed char *) throw();
extern "C" const signed char *func_0047E1C8(const signed char *) throw();
extern "C" unsigned int func_004A8368(const signed char *) throw();
extern "C" int func_004E5700(const signed char *, const signed char *, unsigned int);

extern "C" int func_0047E2E8(const signed char *a, const signed char *b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (*a != '/') {
        return 0;
    }
    unsigned int la = func_004A8368(a);
    unsigned int lb = func_004A8368(b);
    if (la == 1) {
        return 1;
    }
    if (lb < la) {
        return 0;
    }
    const signed char *p = func_0047E188(a);
    const signed char *q = func_0047E188(b);
    while (*p != 0) {
        const signed char *e1 = func_0047E1C8(p);
        const signed char *e2 = func_0047E1C8(q);
        if (e1 - p != e2 - q) {
            return 0;
        }
        if (func_004E5700(p, q, e1 - p) != 0) {
            return 0;
        }
        p = func_0047E188(e1);
        q = func_0047E188(e2);
    }
    return 1;
}
