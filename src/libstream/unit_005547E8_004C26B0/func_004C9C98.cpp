typedef unsigned short u16;
struct S;

extern "C" void *func_004C9C60(struct S *arg0);

extern "C" void *func_004C9C98(struct S *arg0) {
    u16 *p = (u16 *)func_004C9C60(arg0);
    return (char *)p + *p;
}
