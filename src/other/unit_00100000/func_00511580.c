/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_005E0298;
extern void func_00511A60(int a0, int a1, int a2, int a3, Pmf m);

void func_00511580(int a0, int a1, int a2, int a3) {
    func_00511A60(a0, a1, a2, a3, D_005E0298);
}
