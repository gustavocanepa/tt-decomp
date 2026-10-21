struct Node { int a; int len; int pad8; };
struct Args { int a0; int a4; Node *n8; Node *nC; Node *n10; };
struct Str9 { char c[9]; };
extern char *D_0059834C;
extern char D_00613200[];
extern char D_006131F8[];
extern "C" int func_004B87F8(int, char *);
extern "C" int func_004B8910(int, char *);
extern "C" int func_004B8A18(int, char *, int, int, int);
extern "C" void func_004A4D68(char *);
extern "C" void func_004A4DD8(char *);
extern "C" int func_004A8368(char *);
extern "C" void func_004F7A30(char *, char *);
extern "C" char *func_004F7B74(char *, const char *);

extern "C" int func_004B9A70(int arg0, Args *arg1) {
    struct { int r; char pad[12]; char path[64]; } L;
    func_004A4D68(D_0059834C + 0x34);
    char *p = L.path;
    L.path[0] = 0x2F;
    func_004F7B74(p + 1, *(char **)arg1);
    L.r = func_004B87F8(arg0, p);
    if (L.r == 0 || (L.r == 2 && (L.r = func_004B8910(arg0, p)) == 0)) {
        func_004F7A30(p, D_006131F8);
        char *s2 = p + func_004A8368(p);
        func_004F7B74(s2, *(char **)arg1->n8);
        L.r = func_004B8A18(arg0, p, arg1->n8->len, 0, arg1->n8->pad8);
        if (L.r == 0) {
            if (arg1->nC != 0) {
                func_004F7B74(s2, *(char **)arg1->nC);
                L.r = func_004B8A18(arg0, p, arg1->nC->len, 0, arg1->nC->pad8);
                if (L.r != 0) goto done;
            }
            if (arg1->n10 != 0) {
                func_004F7B74(s2, *(char **)arg1->n10);
                L.r = func_004B8A18(arg0, p, arg1->n10->len, 0, arg1->n10->pad8);
                if (L.r != 0) goto done;
            }
            *(Str9 *)s2 = *(Str9 *)D_00613200;
            L.r = func_004B8A18(arg0, p, arg1->a4, 0, 0x3C4);
        }
    }
done:
    func_004A4DD8(D_0059834C + 0x34);
    return L.r;
}
