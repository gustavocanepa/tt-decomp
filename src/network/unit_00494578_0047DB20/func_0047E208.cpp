/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" const signed char *func_0047E188(const signed char *) throw();
extern "C" const signed char *func_0047E1C8(const signed char *) throw();
extern "C" int func_004E5700(const signed char *, const signed char *, unsigned int);

extern "C" const signed char *func_0047E208(const signed char *a, const signed char *b) {
    if (a == 0) {
        return b;
    }
    const signed char *p = func_0047E188(a);
    const signed char *q = func_0047E188(b);
    while (*p != 0) {
        const signed char *e1 = func_0047E1C8(p);
        const signed char *e2 = func_0047E1C8(q);
        if (e1 - p != e2 - q) {
            break;
        }
        if (func_004E5700(p, q, e1 - p) != 0) {
            break;
        }
        p = func_0047E188(e1);
        q = func_0047E188(e2);
    }
    return func_0047E188(q);
}
