/* compiler: ee-gcc2.9-991111 */
struct Pair { int a; int b; };
extern struct Pair D_005A40D0[8];
extern char D_005A3968[], D_005A40A8[];
extern void func_00504008(int, int);
extern void func_00504018(unsigned int, void *, unsigned int);
extern void func_004FAAA0(int);
extern int func_00504060(int);
void func_00504070(void) {
    unsigned int i;
    struct Pair *p;
    struct Pair *base;
    if (!(*(volatile unsigned int *)0x10001810 & 0x100)) {
        i = 2;
        base = D_005A40D0;
        p = base + 2;
        func_00504008(base[0].a, base[0].b);
        func_00504018(0x80076000, D_005A3968, 0x740);
        func_00504018(0x82000, D_005A40A8, 0x28);
        func_004FAAA0(0);
        func_004FAAA0(2);
        { int a = *(volatile int *)&base[1].a; func_00504008(a, base[1].b); }
        do {
            int value = func_00504060(p->a);
            i++;
            func_00504008(p->a, value);
            p++;
        } while (i < 8);
    }
}
