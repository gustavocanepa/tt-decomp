/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Sema { int a; int max; int init; int d; int e; const char *opt; };
struct Blk { int sema; int *res; int n8; char path[0x400]; char path2[0x400]; char data[0x400]; int size; };
extern struct Blk D_0078DD00;
extern int D_005A315C;
extern char D_0078F400[];
extern char D_0078E940[];
extern char D_00617AB8[];
extern int func_004FA820(struct Sema *);
extern void func_004FA830(int);
extern int func_004FA860(int);
extern u32 func_004FEDD8(int, int, int, int, int, int, int, int, int, int);
extern int func_004FF348(int);
extern void func_004FF378(void);
extern void func_004FF470(void);

extern void func_004FDAF8(void *, int);

int func_00500E00(const unsigned char *path, const unsigned char *path2, const unsigned char *data, int size)
{
    struct Blk *b = &D_0078DD00;
    int i;
    int sema;
    int res;
    int ok;
    struct Sema sp;
    func_004FF348(14);
    if (D_005A315C == 0)
        func_004FF470();
    for (i = 0; i < 0x400; i++) {
        if ((b->path[i] = path[i]) == 0)
            break;
    }
    if (i == 0x400) {
        b->path[0x3FF] = 0;

    }
    if (path2 == 0) b->path2[0]=0;
    else {
        for (i=0; i<0x400; i++) {
            if ((b->path2[i]=path2[i]) == 0) break;
        }
        if(i==0x400) b->path2[0x3ff]=0;
    }
    if(size>0x400) {func_004FF378(); return -7;}
    for(i=0;i<size;i++) b->data[i]=data[i];
    b->size=size;
    sp.max = 1;
    sp.init = 0;
    sp.opt = D_00617AB8;
    sema = func_004FA820(&sp);
    b->res = &res;
    b->sema = sema;
    b->n8 = 4;
    func_004FDAF8(&D_0078DD00,0xC10);
    if ((int)func_004FEDD8((int)D_0078F400, 14, 0, (int)&D_0078DD00, 0xC10, (int)D_0078E940, 4, 0, 0, 0) < 0) {
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
