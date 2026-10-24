/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VObj { int data; char *vtbl; };
struct VEntryI { short delta; short index; int (*fn)(void *); };
static inline int vi(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x68);
    return e->fn((char *)o + e->delta);
}
extern "C" void func_001B7F40(void *, int) throw();
extern "C" void func_001B7F98(void *, void *) throw();
extern "C" int func_001BA1F8(int, int);
extern "C" void func_00202758(void *, void *);
extern "C" void func_00202788(void *, int);
extern "C" void func_002C0FE8(int);
extern "C" void func_002C1050(int);
extern "C" void func_001B8BB8(int *arg0, void *arg1, int arg2, VObj **arg3) {
    int buf0[4];
    int buf1[4];
    int temp;
    if (arg2 > 0) {
        func_001B7F98(buf0, arg1);
        int self = buf0[0];
        int *ptemp = &temp;
        temp = func_001BA1F8(self, vi(arg3[0]));
        int *p1 = buf1;
        func_00202758(p1, ptemp);
        if (arg0 != p1) {
            int newVal = *p1;
            if (newVal != 0) func_002C0FE8(newVal);
            int oldVal = *arg0;
            if (oldVal != 0) func_002C1050(oldVal);
            *arg0 = newVal;
        }
        func_00202788(p1, 2);
        func_001B7F40(buf0, 2);
    }
}
