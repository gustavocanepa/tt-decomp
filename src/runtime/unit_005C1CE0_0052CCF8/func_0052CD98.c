/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_005EA8F0;
extern void func_0052D090(int a0, int a1, int a2, int a3, Pmf m);

void func_0052CD98(int a0, int a1, int a2, int a3) {
    func_0052D090(a0, a1, a2, a3, D_005EA8F0);
}
