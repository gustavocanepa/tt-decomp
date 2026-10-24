/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Sema { int a; int max; int init; int d; int e; const char *opt; };
struct Ent { int p0; int p4; int p8; int pc; };
struct Blk { int sema; int *res; int n8; int pc; int p10; };
extern struct Blk D_0078DD00;
extern struct Ent D_0078F200[];
extern int D_005A315C;
extern char D_0078F400[];
extern char D_0078E940[];
extern char D_006179F8[];
extern int func_004FA820(struct Sema *);
extern void func_004FA830(int);
extern int func_004FA860(int);
extern u32 func_004FEDD8(int, int, int, int, int, int, int, int, int, int);
extern struct Ent *func_004FEEC8(unsigned int);
extern int func_004FF348(int);
extern void func_004FF378(void);

static inline int clamp_result(int x, int limit) { return x > limit ? 0 : x; }

int func_004FFC00(unsigned int fd)
{
    struct Blk *b = &D_0078DD00;
    struct Ent *e;
    int sema;
    int res;
    int ok;
    struct Sema sp;
    e = func_004FEEC8(fd);
    func_004FF348(1);
    if (D_005A315C == 0 || e == 0 || e->p4 == 0) {
        func_004FF378();
        return -9;
    }
    b->pc = e->p0;
    b->p10 = e - D_0078F200;
    sp.max = 1;
    sp.init = 0;
    sp.opt = D_006179F8;
    sema = func_004FA820(&sp);
    b->sema = sema;
    b->res = &res;
    b->n8 = 4;
    if ((int)func_004FEDD8((int)D_0078F400, 1, 0, (int)&D_0078DD00, 0x14, (int)D_0078E940, 4, 0, 0, 0) < 0) {
        func_004FA830(sema);
        func_004FF378();
        return -0xB;
    }
    e->p4 = 0;
    ok = *(int *)((u32)D_0078E940 | 0x20000000);
    func_004FF378();
    if (ok == 0) {
        func_004FA830(sema);
        return -0xB;
    }
    func_004FA860(sema);
    func_004FA830(sema);
    return clamp_result(res, -1);
}
