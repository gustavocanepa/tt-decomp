/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_005DFDF8;
extern void func_00510280(int a0, int a1, int a2, int a3, Pmf m);

void func_0050FBB8(int a0, int a1, int a2, int a3) {
    func_00510280(a0, a1, a2, a3, D_005DFDF8);
}
