/* compiler: ee-gcc2.9-991111 */
typedef struct Node { char pad[0x10]; int f10; } Node;
extern int D_005A0BB0;
extern int D_00779FF0;
extern int D_00779FF4;
extern char D_006139D0[];
extern char D_006139F0[];
extern char D_00613A28[];
extern char D_00613A50[];
extern char D_00613A88[];
void func_004D28C0(void);
Node **func_004D3E80(int *);
int func_004D4A18(Node *);
int func_004D5B30(void);
void func_004D9D90(unsigned int *, unsigned int *);
int func_004D9E18(unsigned int *, int, unsigned int *);
int func_004D9FB0(int, int, int, unsigned int *);
void func_004FD2D0(const char *, ...);

int func_004D2590(void) {
    unsigned int sp[3];
    int r;
    Node **pp;
    Node *n;
    Node *t;
    if (D_005A0BB0 == 0) return 0x81058001;
    func_004D9D90(sp, 0);
    if (D_00779FF0 != (int)sp[0]) func_004FD2D0(D_006139D0);
    r = func_004D9E18(&sp[1], 1, &sp[2]);
    if (sp[2] == 1 && (int)sp[1] == D_00779FF4) {
        sp[2] = 0;
    } else if (sp[2] == 0) {
        if (D_00779FF4 != -1) {
            func_004FD2D0(D_006139F0);
        }
    }
    if (sp[2] != 0) {
        func_004FD2D0(D_00613A28, r);
        return 0x81050010;
    }
    if (D_00779FF4 != -1) {
        r = func_004D9FB0(D_00779FF4, 0, 0, sp);
        if (r != D_00779FF4) {
            func_004FD2D0(D_00613A50, r);
            for (;;) ;
        }
        D_00779FF4 = -1;
    } else {
        func_004D28C0();
    }
    func_004D5B30();
    pp = func_004D3E80(0);
    n = *pp;
    if (n) {
        do {
            r = func_004D4A18(n);
            if (r < 0) {
                func_004FD2D0(D_00613A88, n->f10, r, n->f10);
                for (;;) ;
            }
            t = *pp;
            n = t;
        } while (t);
    }
    D_00779FF0 = 0;
    D_005A0BB0 = 0;
    return 0;
}
