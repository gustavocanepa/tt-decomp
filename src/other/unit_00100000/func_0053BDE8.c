/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_005EDA58;
extern void func_0053C268(int a0, int a1, int a2, int a3, Pmf m);

void func_0053BDE8(int a0, int a1, int a2, int a3) {
    func_0053C268(a0, a1, a2, a3, D_005EDA58);
}
