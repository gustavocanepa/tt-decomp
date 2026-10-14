/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001E6428(void *, int) throw();
extern "C" void func_001E6480(void *, void *) throw();
extern "C" void func_001E9558(char *, void *);
extern "C" void *func_00202758(void *, void *);
extern "C" void func_00202788(void *, int);
struct Value { void *p; int pad[3]; };
extern "C" void MRootWindow__setFocus(void *arg0, void *arg1, int count, void **args) {
    char *a[4];
    Value b;
    Value temp;
    if (count > 0) {
        func_001E6480(a, arg1);
        Value *pt = &temp;
        pt->p = args[0];
        Value *pb = &b;
        func_00202758(pb, pt);
        func_001E9558(a[0], pb->p);
        func_00202788(pb, 2);
        func_001E6428(a, 2);
    }
}
