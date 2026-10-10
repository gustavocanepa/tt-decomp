/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_005EA8E8;
extern void func_0052CF90(int a0, int a1, int a2, int a3, Pmf m);

void func_0052CD70(int a0, int a1, int a2, int a3) {
    func_0052CF90(a0, a1, a2, a3, D_005EA8E8);
}
