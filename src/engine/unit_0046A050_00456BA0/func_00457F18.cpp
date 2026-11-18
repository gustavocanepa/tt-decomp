struct __attribute__((packed)) V { long long n; };
struct Arg { int a, b; };
struct Obj {
    char p0[0xA88];
    char p1[0xAB0 - 0xA88];
    V v0;
    V v1;
    char p2[0xAC0 - 0xAC0];
};
struct __attribute__((packed)) Obj2 {
    char p0[0xA88];
    char p1[8 + 0x20 - 0x8 + 0];
};
extern "C" {
void func_00457EA0(void *);
void func_00459898(void *, int, int);
void func_0045D0B0(void *);
void *func_004F6678(void *, int, int);
}
struct O {
    char p0[0xAB0];
    V v0;
    V v1;
    char p1[0xD80 - 0xAC0];
    int flag;
    char p2[0xDCC - 0xD84];
    int m1, m2;
    char p3[0xDDC - 0xDD4];
    int m3;
};
extern "C" void func_00457F18(O *o, V *a, Arg *c)
{
    func_00457EA0(o);
    o->v0 = *a;
    o->v1 = *(V *)c;
    func_0045D0B0((char *)o + 0xAC0);
    o->flag = 1;
    int i = 2;
    do {
        func_004F6678((char *)o + 0xD84, 0, 0x18);
    } while (--i >= 0);
    o->m1 = 0;
    o->m2 = 0;
    o->m3 = 0;
    func_00459898((char *)o + 0xA88, c->b, c->a);
}
