/* compiler: ee-gcc2.9-991111 */
typedef struct { int a; int b; int c; int d; unsigned char sbuf[0x80]; unsigned char rbuf[0x80]; int res; } Req;
extern int D_0078A600;
extern Req D_00789E40;
extern char D_00789D40[];
void func_004DEC40(int, ...);
void func_004FA840(int);
int func_004FA860(int);
int func_004FE530(void *, int, int, void *, int, void *, int, void *, void *);

/* sceDbcSRData */
int func_004DE550(int arg0, int arg1, int *slen, unsigned char *sdata, int *rlen, unsigned char *rdata) {
    Req *r;
    int i;
    int res;
    func_004FA860(D_0078A600);
    r = &D_00789E40;
    D_00789E40.a = arg0;
    r->b = arg1;
    r->c = *slen;
    r->d = *rlen;
    for (i = 0; i < *slen; i++) r->sbuf[i] = sdata[i];
    if (func_004FE530(D_00789D40, 0x80001318, 0, &D_00789E40, 0x90, &D_00789E40, 0x90, 0, 0) < 0) {
        func_004DEC40((int)"sceDbcSRData: rpc error\n");
        func_004FA840(D_0078A600);
        return 0;
    }
    res = r->res;
    if (res >= 0) {
        *slen = r->c;
        *rlen = r->d;
        for (i = 0; i < r->d; i++) rdata[i] = r->rbuf[i];
        res = r->res;
    }
    func_004FA840(D_0078A600);
    return res;
}
