/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;

struct IopBufReq {
    unsigned int size;
    unsigned int count;
};

extern struct IopBufReq D_0078DD00;
extern int D_005A315C;
extern char D_0078F400[];
extern char D_0078E940[];
extern int func_004FECD0(void);
extern u32 func_004FEDD8(int, int, int, int, int, int, int, int, int, int);
extern int func_004FF348(int);
extern void func_004FF378(void);
extern void func_004FF470(void);
extern int func_004FF678(void);

/* sceFsSetIopBuf */
int func_004FF740(unsigned int buffsize, unsigned int buffcnt)
{
    struct IopBufReq *req;
    int ret;

    func_004FF348(0xFE);
    if (D_005A315C == 0)
        func_004FF470();
    if (func_004FF678() != 0) {
        func_004FF378();
        return 0xFFFEFFFC;
    }
    if (func_004FECD0() != 0) {
        func_004FF378();
        return -0x10;
    }
    if ((buffsize & 0x3FFF) != 0 || buffsize == 0 || buffsize > 0xFFFFF || buffcnt == 0 || buffcnt > 0x20) {
        func_004FF378();
        return -0x16;
    }
    D_0078DD00.size = buffsize;
    req = &D_0078DD00;
    req->count = buffcnt;
    if ((int)func_004FEDD8((int)D_0078F400, 0xFE, 0, (int)req, 8, (int)D_0078E940, 4, 0, 0, 0) < 0) {
        func_004FF378();
        return -0xB;
    }
    ret = *(int *)((u32)D_0078E940 | 0x20000000);
    func_004FF378();
    return ret;
}
