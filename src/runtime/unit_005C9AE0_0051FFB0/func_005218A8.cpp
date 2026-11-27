/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" u32 func_004B2850(void *);
extern "C" u32 func_004B2BD8(void *);
extern "C" void func_005218A8(u32 *p, u32 n, void *a, void *b) {
    while (n >= 4) {
        u32 x, *q;
        n -= 4;
        u32 r = func_004B2850(a);
        x = *p;
        x = x ^ r;
        q = p;
        p++;
        *q = x - func_004B2BD8(b);
    }
    {
        u8 *bp = (u8 *)p;
        while (n != 0) {
            u32 x;
            u8 *q;
            u32 r = func_004B2850(a);
            n--;
            x = *bp;
            x = x ^ r;
            q = bp;
            bp++;
            *q = x - func_004B2BD8(b);
        }
    }
}
