/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_005EDA20;
extern void func_0053BF80(int a0, int a1, int a2, int a3, Pmf m);

void func_0053BCD0(int a0, int a1, int a2, int a3) {
    func_0053BF80(a0, a1, a2, a3, D_005EDA20);
}
