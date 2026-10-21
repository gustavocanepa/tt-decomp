/* compiler: ee-gcc2.9-991111 */
extern int func_00503C50(void);
extern void func_00503BE8(int, int);
extern void func_00503BF8(unsigned int, void *, int);
extern void func_004FAAA0(int);
extern int func_00503C40(int);
extern int D_005A3948[];
extern char D_005A31A0[];
void func_00503CB8(void) {
    if (func_00503C50()) {
        int first;
        unsigned int i = 2;
        int *base = D_005A3948;
        int *p = base + 4;
        func_00503BE8(base[0], base[1]);
        func_00503BF8(0x80074000, D_005A31A0, 0x7A8);
        func_004FAAA0(0);
        func_004FAAA0(2);
        first = *(volatile int *)&base[2];
        func_00503BE8(first, base[3]);
        do {
            int value = func_00503C40(*p);
            i++;
            func_00503BE8(*p, value);
            p += 2;
        } while (i < 3);
    }
}
