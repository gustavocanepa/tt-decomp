/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Sema { int a; int max; int init; int d; int e; const char *opt; };
struct Blk { int sema; int *res; int n8; char path[0x400]; };
extern struct Blk D_0078DD00;
extern int D_005A315C;
extern char D_0078F400[];
extern char D_0078E940[];
extern char D_00617A88[];
extern int func_004FA820(struct Sema *);
extern void func_004FA830(int);
extern int func_004FA860(int);
extern u32 func_004FEDD8(int, int, int, int, int, int, int, int, int, int);
extern int func_004FF348(int);
extern void func_004FF378(void);
extern void func_004FF470(void);

int func_00500A58(const unsigned char *path, int arg1)
{
    struct Blk *b = &D_0078DD00;
    int i;
    int sema;
    int res;
    int ok;
    struct Sema sp;
    func_004FF348(arg1);
    if (D_005A315C == 0)
        func_004FF470();
    for (i = 0; i < 0x400; i++) {
        if ((b->path[i] = path[i]) == 0)
            break;
    }
    if (i == 0x400) {
        b->path[0x3FF] = 0;
        i = 0x3FF;
    }
    sp.max = 1;
    sp.init = 0;
    sp.opt = D_00617A88;
    sema = func_004FA820(&sp);
    b->res = &res;
    b->sema = sema;
    b->n8 = 4;
    if ((int)func_004FEDD8((int)D_0078F400, arg1, 0, (int)&D_0078DD00, i + 0xD, (int)D_0078E940, 4, 0, 0, 0) < 0) {
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
