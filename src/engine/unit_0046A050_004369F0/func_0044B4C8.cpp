/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Val { int type; char pad[12]; };
struct Node { char pad[0x58]; Node *parent; };
struct Obj { char pad[0x14]; Node *node; };
extern Rep D_005A4C58;
extern char D_00601E30[], D_006021B8[];
extern "C" void *func_0043D3E0(Val *, Val *) throw();
extern "C" void func_0043D510(Val *) throw();
extern "C" void func_0043DE58(Val *, Node *) throw();
extern "C" Val *func_0043E148(Val *, Val *, Str *) throw();
extern "C" void func_00447D48(Str *) throw();
extern "C" Val *func_0044B2B0(Val *, Obj *, Str *, int, int, int) throw();
extern "C" void func_004A45D0(void *) throw();
extern "C" void func_004A6448(const char *, ...);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Node *func_0056BB78(Node *);
extern "C" Str *func_0056C780(Str *, char *, char *, const char *, const char *);
extern "C" void func_0044B4C8(Obj *self, char *p, int a2, int a3, int a4, char **start, Val *value) {
    Str s;
    Val tmp;
    func_0043D510(value);
    if (*p == '/') {
        Node *n = self->node;
        if (n->parent) n = func_0056BB78(n->parent);
        func_0043DE58(value,n);
        p++;
    }
    *start = p;
    char c;
    while ((c = *p++) != 0) {
        if ((unsigned)(c - '.') < 2 || c == ':') {
            char *first = *start;
            if (p - first >= 2) {
                Str *ps = &s;
                char *last = p-1;
                char *d;
                if (D_005A4C58.sel) d = strobe__toUpper(&D_005A4C58);
                else { d = (char *)(&D_005A4C58+1); D_005A4C58.ref++; }
                ps->p = d;
                func_0056C780(ps,d,d+((Rep *)d)[-1].len,first,last);
                func_00447D48(&s);
                if ((value->type ^ 1) == 0) {
                    func_0044B2B0(&tmp,self,&s,a2,a3,a4);
                    func_0043D3E0(value,&tmp);
                    func_0043D510(&tmp);
                } else {
                    func_0043E148(&tmp,value,&s);
                    func_0043D3E0(value,&tmp);
                    func_0043D510(&tmp);
                }
                if ((value->type ^ 1) == 0) {
                    const char *text;
                    int len = ((Rep *)s.p)[-1].len;
                    if (len == 0) text = D_00601E30;
                    else { s.p[len] = 0; text = s.p; }
                    func_004A6448(D_006021B8,text);
                }
                Rep *r = (Rep *)(s.p - 16);
                if (--r->ref == 0) func_004A45D0(r);
            }
            *start = p;
        }
    }
}
