/* compiler: ee-gcc2.9-991111 */
typedef struct { int a; int b; int c; int d; int e; unsigned char buf[16]; int res; void *f28; void *f2c; } Req;
typedef struct { int a; int b; int c; int d; int e; unsigned char buf[16]; } Arg;
extern int D_005A0D50;
extern int D_0078A600;
extern Req D_00789E40;
extern char D_00789D40[];
void func_004DEC40(int, ...);
void func_004FA840(int);
int func_004FA860(int);
int func_004FE530(void *, int, int, void *, int, void *, int, void *, void *);

int func_004DDE28(Arg *arg0, void *arg1, void *arg2) {
    Req *r;
    int i;
    int res;
    if (D_005A0D50 == 0) return 0;
    func_004FA860(D_0078A600);
    { int a = arg0->a;
    r = &D_00789E40;
    D_00789E40.a = a; }
    r->f28 = arg1;
    r->f2c = arg2;
    r->b = arg0->b;
    r->c = arg0->c;
    r->d = arg0->d;
    r->e = arg0->e;
    for (i = 0; i < 16; i++) r->buf[i] = arg0->buf[i];
    if (func_004FE530(D_00789D40, 0x80001301, 0, &D_00789E40, 0x90, &D_00789E40, 0x90, 0, 0) < 0) {
        func_004DEC40((int)"sceDbcCreateSocket: rpc error\n");
        func_004FA840(D_0078A600);
        return 0;
    }
    res = r->res;
    func_004FA840(D_0078A600);
    return res;
}
