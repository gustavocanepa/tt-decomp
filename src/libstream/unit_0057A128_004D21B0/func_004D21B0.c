/* compiler: ee-gcc2.9-991111 */
struct D { short s0; short s2; short s4; short s6; int w8; int wc; };
extern struct D *func_004D2340(void);
extern void func_004FA420(int, int, int);
extern void func_004FA520(int, int);
extern int func_004FAB60(int);
extern int func_004FB300(int);
#define CSR (*(volatile unsigned long *)0x12001000)

void func_004D21B0(short mode, short a1, short a2, short a3) {
    struct D *d;
    switch (mode) {
    case 0:
        d = func_004D2340();
        CSR = 0x200;
        d->s0 = a1;
        d->s2 = a2;
        d->s6 = (CSR >> 16) & 0xFF;
        func_004FAB60(0xFF00);
        d->s4 = (a3 != 0);
        if (d->w8 != 0) {
            func_004FB300(2);
            func_004FA520(2, d->wc);
            d->w8 = 0;
            d->wc = 0;
        }
        return func_004FA420(a1 & 1, a2 & 0xFF, a3 & 1);
    case 1:
        CSR = 0x100;
        return;
    case 5:
        d = func_004D2340();
        d->s4 = (a3 != 0);
        d->s0 = a1;
        d->s2 = a2;
        d->s6 = (CSR >> 16) & 0xFF;
        return func_004FA420(a1 & 1, a2 & 0xFF, a3 & 1);
    default:
        return;
    }
}
