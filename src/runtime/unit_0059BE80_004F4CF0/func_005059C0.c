/* compiler: ee-gcc2.9-991111 */
struct Entry { int handler, arg, gp, pad; };
extern struct Entry D_00791BC8[];
extern struct Entry *D_005A4130;
extern unsigned int D_005A4134;
int func_005038D8(void);
int func_00503928(void);
int func_005059C0(int id, int handler, int arg) {
    struct Entry *table;
    unsigned int count;
    int intr, gp;
    if (id < 0) {
        id &= 0x7fffffff;
        table = D_00791BC8;
        count = 32;
    } else {
        table = D_005A4130;
        count = D_005A4134;
    }
    if ((unsigned int)id >= count) return 0x80000069;
    intr = func_005038D8();
    table[id].handler = handler;
    table[id].arg = arg;
    __asm__ volatile ("daddu %0,$28,$0" : "=r" (gp));
    table[id].gp = gp;
    if (intr) func_00503928();
    return 0;
}
