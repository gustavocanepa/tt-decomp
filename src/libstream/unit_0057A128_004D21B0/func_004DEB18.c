/* compiler: ee-gcc2.9-991111 */
typedef struct { int a; int b; int c; unsigned char buf[0x80]; int res; } Req;
extern int D_0078A600;
extern Req D_00789E40;
extern char D_00789D40[];
void func_004DEC40(int, ...);
void func_004FA840(int);
int func_004FA860(int);
int func_004FE530(void *, int, int, void *, int, void *, int, void *, void *);

int func_004DEB18(int arg0, int arg1, int *arg2, unsigned char *arg3) {
    Req *r;
    int i;
    int res;
    func_004FA860(D_0078A600);
    r = &D_00789E40;
    D_00789E40.a = arg0;
    r->b = arg1;
    r->c = *arg2;
    if (func_004FE530(D_00789D40, 0x8000131A, 0, r, 0x90, r, 0x90, 0, 0) < 0) {
        func_004DEC40((int)"sceDbcReceiveData: rpc error\n");
        func_004FA840(D_0078A600);
        return 0;
    }
    res = r->res;
    if (res >= 0) {
        *arg2 = r->c;
        for (i = 0; i < r->c; i++) arg3[i] = r->buf[i];
        res = r->res;
    }
    func_004FA840(D_0078A600);
    return res;
}
