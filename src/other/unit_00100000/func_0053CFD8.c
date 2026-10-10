/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_005EDFA0;
extern void func_0053D198(int a0, int a1, int a2, int a3, Pmf m);

void func_0053CFD8(int a0, int a1, int a2, int a3) {
    func_0053D198(a0, a1, a2, a3, D_005EDFA0);
}
