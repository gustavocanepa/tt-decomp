/* compiler: ee-gcc2.9-991111 */
struct Pair { int reg; int value; };
extern struct Pair D_005A44C0[8];
extern char D_005A4140[];
extern int D_005A44B8;
extern void func_00506498(int, int);
extern void func_00506440(unsigned int, void *, int);
extern void func_004FAAA0(int);
extern int func_00506488(int);
void func_005064A8(void) {
    unsigned int i = 3;
    struct Pair *base = D_005A44C0;
    struct Pair *p;
    func_00506498(base[0].reg, base[0].value);
    func_00506440(0x80075000U, D_005A4140, 0x330);
    func_004FAAA0(0);
    func_004FAAA0(2);
    func_00506498(base[1].reg, base[1].value);
    func_00506498(base[2].reg, base[2].value);
    p = base + 3;
    do {
        int v = func_00506488(p->reg);
        i++;
        func_00506498(p->reg, v);
        p++;
    } while (i < 8);
    D_005A44B8 = func_00506488(3);
}
