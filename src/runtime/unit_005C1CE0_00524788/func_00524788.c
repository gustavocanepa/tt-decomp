/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_005E8880;
extern void func_00524880(int a0, int a1, int a2, int a3, Pmf m);

void func_00524788(int a0, int a1, int a2, int a3) {
    func_00524880(a0, a1, a2, a3, D_005E8880);
}
