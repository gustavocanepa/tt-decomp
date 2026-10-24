/* compiler: ee-gcc2.9-991111 */
typedef struct { int a; int b; int c; unsigned char buf[0x80]; int res; } Req;
extern int D_0078A600;
extern Req D_00789E40;
extern char D_00789D40[];
void func_004DEC40(int, ...);
void func_004FA840(int);
int func_004FA860(int);
int func_004FE530(void *, int, int, void *, int, void *, int, void *, void *);

/* sceDbcSendData */
int func_004DE6E0(int arg0, int arg1, int *len, unsigned char *data) {
    Req *r;
    int i;
    int res;
    func_004FA860(D_0078A600);
    r = &D_00789E40;
    D_00789E40.a = arg0;
    r->b = arg1;
    r->c = *len;
    for (i = 0; i < *len; i++) r->buf[i] = data[i];
    if (func_004FE530(D_00789D40, 0x80001319, 0, &D_00789E40, 0x90, &D_00789E40, 0x90, 0, 0) < 0) {
        func_004DEC40((int)"sceDbcSendData: rpc error\n");
        func_004FA840(D_0078A600);
        return 0;
    }
    res = r->res;
    if (res >= 0) {
        *len = r->c;
        res = r->res;
    }
    func_004FA840(D_0078A600);
    return res;
}
