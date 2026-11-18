/* compiler: ee-gcc2.9-991111 */
typedef int s32;
struct Pkt { int p0; int p4; int p8; int pc; int p10; struct Pkt *self; int p18; struct Cl *cl; int rpc; int ssize; int recv; int rsize; int flag; int cmd34; };
struct Cl { struct Pkt *pkt; int pid; int sema; int pc; int p10; int cmd; int gp; void *endfunc; void *edata; int c24; };
struct Sema { int a; int max; int init; int d; int e; const char *opt; };
extern char D_0078DC80[];
extern char D_00617928[];
extern int func_004FA820(struct Sema *);
extern int func_004FA830(int);
extern int func_004FA860(int);
extern s32 func_004FD930(s32, struct Pkt *, s32, s32, s32, s32);
extern void func_004FDAF8(void *, int);
extern struct Pkt *func_004FDD70(int);
extern void func_004FDE18(struct Pkt *);

int func_004FE530(struct Cl *cl, int rpc, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *endfunc, void *edata) {
    struct Pkt *pkt;
    struct Sema sp;
    int r;
    pkt = func_004FDD70((int)D_0078DC80);
    if (pkt == 0) return -1;
    cl->edata = edata;
    cl->pid = pkt->p18;
    cl->pkt = pkt;
    cl->endfunc = endfunc;
    { int gp; __asm__ volatile("daddu %0, $28, $0" : "=r" (gp)); cl->gp = gp; }
    pkt->rpc = rpc;
    pkt->ssize = ssize;
    pkt->recv = (int)recv;
    pkt->rsize = rsize;
    pkt->self = pkt;
    pkt->cl = (struct Cl *)cl;
    pkt->cmd34 = cl->c24;
    if (!(mode & 2)) {
        if (send == recv) {
            func_004FDAF8(send, ssize >= rsize ? ssize : rsize);
        } else {
            if (ssize > 0) func_004FDAF8(send, ssize);
            if (rsize > 0) func_004FDAF8(recv, rsize);
        }
    }
    if (mode & 1) {
        if (endfunc == 0) pkt->flag = 0; else pkt->flag = 1;
        cl->sema = -1;
        if (func_004FD930(0x8000000A, pkt, 0x40, (s32)send, cl->cmd, ssize) != 0) return 0;
        func_004FDE18(pkt);
        return -2;
    }
    sp.init = 0;
    sp.max = 1;
    sp.opt = D_00617928;
    cl->sema = func_004FA820(&sp);
    if (cl->sema < 0) {
        func_004FDE18(pkt);
        return -3;
    }
    pkt->flag = 1;
    if (func_004FD930(0x8000000A, pkt, 0x40, (s32)send, cl->cmd, ssize) == 0) {
        func_004FA830(cl->sema);
        func_004FDE18(pkt);
        return -2;
    }
    func_004FA860(cl->sema);
    func_004FA830(cl->sema);
    return 0;
}
