typedef unsigned short u16;
struct S;

extern "C" void *func_004C9C50(struct S *arg0);

extern "C" void *func_004C9C70(struct S *arg0) {
    u16 *p = (u16 *)func_004C9C50(arg0);
    return (char *)p + *p;
}
