/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
struct Obj { char pad[0x18]; int *tab; int get(int i) { return tab[i]; } };
struct UF { float f; } __attribute__((packed));
extern "C" float func_003F5150(int, float);
static inline int rd16(unsigned char **c) {
    unsigned char *p = *c;
    *c = p + 2;
    return (p[1] << 8) | p[0];
}
extern "C" void func_003F4D10(float scale, unsigned char **cur, Obj *obj, float *out, int n, unsigned mask) {
    int i = 0;
    if (n > 0) {
        float *dst = out;
        do {
            int bit = 1 << i;
            i++;
            if (mask & bit) {
                unsigned char *p = *cur;
                int lo = p[0];
                int idx = (p[1] << 8) | lo;
                *cur = p + 2;
                *dst = func_003F5150(obj->get(idx), scale);
            } else {
                UF *p = (UF *)*cur;
                float v = p->f;
                p++;
                *cur = (unsigned char *)p;
                *dst = v;
            }
            dst++;
        } while (i < n);
    }
}
