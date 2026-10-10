/* compiler: ee-gcc2.9-991111 */
struct Entry { int w[4]; };
extern void func_004FEC60(void);
extern int func_004FA860(int sema);
extern int func_004FA840(int sema);
extern int D_005A3168;
extern struct Entry D_0078F200[];

struct Entry *func_004FEEC8(unsigned int n)
{
    struct Entry *e;
    func_004FEC60();
    func_004FA860(D_005A3168);
    if (n >= 32) {
        func_004FA840(D_005A3168);
        return 0;
    }
    e = &D_0078F200[n];
    func_004FA840(D_005A3168);
    return e;
}
