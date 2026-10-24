/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Sema { int a; int max; int init; int d; int e; const char *opt; };
struct Blk { int sema; int *res; int n8; void *arg; };
extern struct Blk D_0078DD00;
extern int D_005A315C;
extern char D_0078F400[];
extern char D_0078E940[];
extern char D_00617AD0[];
extern int func_004FA820(struct Sema *);
extern void func_004FA830(int);
extern int func_004FA860(int);
extern u32 func_004FEDD8(int, int, int, int, int, int, int, int, int, int);
extern int func_004FF348(int);
extern void func_004FF378(void);
extern void func_004FF470(void);

/* sceFsAddDrv */
int func_00501080(void *drv)
{
    struct Blk *b = &D_0078DD00;
    int sema;
    int res;
    int ok;
    struct Sema sp;
    func_004FF348(0xF);
    if (D_005A315C == 0)
        func_004FF470();
    b->arg = drv;
    sp.max = 1;
    sp.init = 0;
    sp.opt = D_00617AD0;
    sema = func_004FA820(&sp);
    b->sema = sema;
    b->res = &res;
    b->n8 = 4;
    if ((int)func_004FEDD8((int)D_0078F400, 0xF, 0, (int)&D_0078DD00, 0x10, (int)D_0078E940, 4, 0, 0, 0) < 0) {
        func_004FA830(sema);
        func_004FF378();
        return -0xB;
    }
    ok = *(int *)((u32)D_0078E940 | 0x20000000);
    func_004FF378();
    if (ok == 0) {
        func_004FA830(sema);
        return -0xB;
    }
    func_004FA860(sema);
    func_004FA830(sema);
    return res;
}
