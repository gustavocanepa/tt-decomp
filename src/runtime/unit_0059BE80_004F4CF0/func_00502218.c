/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned int u32;

struct SemaParam {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    u32 attr;
    u32 option;
};

struct DevctlArg {
    int pad0;
    int size;
    int addr;
    int count;
};

struct DevctlBuf {
    int sema;
    int *result;
    int rsize;
    char name[0x400];
    char arg[0x400];
    int cmd;
    u32 arglen;
    void *bufp;
    u32 buflen;
};

extern int D_005A315C;
extern struct DevctlBuf D_0078DD00;
extern char D_0078F400[];
extern char D_0078E940[];
extern char D_00617BA8[];

extern int func_004FF348(int);
extern void func_004FF470(void);
extern void func_004FF378(void);
extern int func_004FA820(struct SemaParam *);
extern int func_004FA830(int);
extern int func_004FA860(int);
extern void func_004FDAF8(void *, int);
extern int func_004FEDD8(void *, int, int, void *, int, void *, int, void *, void *, int);

int func_00502218(const char *name, int cmd, struct DevctlArg *arg, u32 arglen, void *bufp, u32 buflen)
{
    struct SemaParam sp;
    int result;
    int sema;
    int rpc;
    int i;
    u32 j;
    int stat;
    struct DevctlBuf *b;

    func_004FF348(0x17);
    b = &D_0078DD00;
    if (D_005A315C == 0) {
        func_004FF470();
    }
    for (i = 0; i < 0x400; i++) {
        if ((b->name[i] = name[i]) == 0) {
            break;
        }
    }
    if (i == 0x400) {
        b->name[0x3FF] = 0;
    }
    if (arglen > 0x400 || buflen > 0x400) {
        goto inval;
    }
    if (cmd == 0x4601) {
        if (arg->size == 0) {
            func_004FF378();
            return 0;
        }
        if (arg->count == 0) {
        inval:
            func_004FF378();
            return -22;
        }
    }
    for (j = 0; j < arglen; j++) {
        b->arg[j] = ((char *)arg)[j];
    }
    b->arglen = arglen;
    b->cmd = cmd;
    sp.init_count = 0;
    sp.max_count = 1;
    sp.option = (u32)D_00617BA8;
    sema = func_004FA820(&sp);
    b->buflen = buflen;
    b->result = &result;
    b->rsize = 4;
    b->bufp = bufp;
    b->sema = sema;
    if (cmd == 0x4601) {
        rpc = 0x1C;
        func_004FDAF8((void *)arg->addr, arg->size * arg->count);
    } else {
        rpc = 0x17;
    }
    func_004FDAF8(&D_0078DD00, 0x81C);
    if (func_004FEDD8(D_0078F400, rpc, 0, &D_0078DD00, 0x81C, D_0078E940, 4, 0, 0, 0) < 0) {
        func_004FA830(sema);
        func_004FF378();
        return -11;
    }
    stat = *(int *)((u32)D_0078E940 | 0x20000000);
    func_004FF378();
    if (stat == 0) {
        func_004FA830(sema);
        return -11;
    }
    func_004FA860(sema);
    func_004FA830(sema);
    return result;
}
