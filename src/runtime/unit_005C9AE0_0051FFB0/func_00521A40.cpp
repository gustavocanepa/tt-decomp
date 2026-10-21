/* compiler: ee-gcc2.96-nsa-nosib */
typedef unsigned char u8;
extern "C" float func_004B28D8(void *);
extern "C" void func_00521A40(void *data, unsigned n, void *rng, void (*swap)(void *, unsigned, unsigned), u8 flag) {
    volatile u8 f = flag;
    unsigned i = n - 1;
    unsigned j;
    while (i != 0) {
        float r = func_004B28D8(rng);
        unsigned k = i;
        unsigned u = k + 1;
        i--;
        float fu = (float)u;
        j = (unsigned)(r * fu);
        swap(data, k, j);
    }
}
