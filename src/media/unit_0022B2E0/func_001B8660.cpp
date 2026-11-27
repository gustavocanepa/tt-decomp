/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VObj { int data; char *vtbl; };
struct VEntryV { short delta; short index; void (*fn)(void *, int, int); };
extern "C" void func_001B7F40(void *, int) throw();
extern "C" void func_001B7F98(void *, void *) throw();
extern "C" void func_001DF1F8(void *, int);
extern "C" void func_001DF250(void *, void *);
extern "C" void func_00202788(void *, int);
extern "C" void func_002027E0(void *, void *);
extern "C" void func_001B8660(void *arg0, void *arg1, int arg2, void *arg3) {
    VObj *buf[4];
    int c[4];
    int a[4];
    int b[4];
    int small = arg2 < 2;
    if (arg2 == 1) {
        func_001B7F98(buf, arg1);
        int *pc = c;
        func_002027E0(pc, arg3);
        VObj *o = buf[0];
        VEntryV *e = (VEntryV *)(o->vtbl + 0x380);
        e->fn((char *)o + e->delta, 0, *pc);
        func_00202788(pc, 2);
        func_001B7F40(buf, 2);
    } else if (!small) {
        func_001B7F98(buf, arg1);
        int *pa = a;
        func_001DF250(pa, arg3);
        int *pb = b;
        func_002027E0(pb, (char *)arg3 + 4);
        VObj *o = buf[0];
        VEntryV *e = (VEntryV *)(o->vtbl + 0x380);
        e->fn((char *)o + e->delta, *pa, *pb);
        func_00202788(pb, 2);
        func_001DF1F8(pa, 2);
        func_001B7F40(buf, 2);
    }
}
