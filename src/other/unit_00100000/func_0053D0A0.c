/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_005EDFC8;
extern void func_0053D480(int a0, int a1, int a2, int a3, Pmf m);

void func_0053D0A0(int a0, int a1, int a2, int a3) {
    func_0053D480(a0, a1, a2, a3, D_005EDFC8);
}
