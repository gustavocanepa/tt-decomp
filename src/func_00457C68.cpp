extern "C" {
void func_0045A6A0(void *);
void func_004597F0(void *);
void func_0045D1D0(void *);
void func_0045D220(void *);
void func_0045D2B0(void *);
int func_00457EA0(void *);
extern char D_005DA1D8[];
}
extern "C" int func_00457C68(char *o)
{
    *(char **)(o + 0x11D0) = D_005DA1D8;
    char *base = o + 0xDE0;
    char *p = base;
    func_0045A6A0(o + 8);
    func_004597F0(o + 0xA88);
    for (int i = 2; i != -1; i--) {
        func_0045D1D0(p);
        p += 0x108;
    }
    char *q = base + 0x318;
    for (int i = 1; i != -1; i--) {
        char *r = q;
        for (int j = 2; j != -1; j--) {
            func_0045D220(r);
            r += 0x24;
        }
        q += 0x6C;
    }
    int i = 0;
    char *s = o;
    for (; i < 2; i++) {
        char *r = s + 0x10F8;
        for (int j = 2; j >= 0; j--) {
            func_0045D2B0(r);
            r += 0x24;
        }
        s += 0x6C;
    }
    return func_00457EA0(o);
}
