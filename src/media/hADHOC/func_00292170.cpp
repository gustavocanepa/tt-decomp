/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int unused; int *begin; int *end; };
struct Code { char pad[0x2c]; Vec v; };
struct Context { char pad[0x38]; int value; };
extern "C" void func_00297E58(Code *, int);
extern "C" int func_002A3A70(int);
extern "C" void func_002A3AC8(int, int);
extern "C" void func_002A75A8(void *, int);
extern "C" void func_002A7A30(void *);
extern "C" void func_002B1578(void *, int);
extern "C" void func_002B2030(void *);
extern "C" int hThread__execCode(void *, int, Code **, void *, int, int);
extern "C" void *func_00292170(void *dst, Context *ctx, Code **code, int *env) {
    int a[4];
    int b[4];
    int valid = 0;
    Code *p = *code;
    if (p) {
        Vec *v = &p->v;
        valid = (v->end - v->begin) != 0;
    }
    if (valid == 0) {
        func_002A7A30(dst);
    } else {
        if (func_002A3A70(*env) == 0) func_002A3AC8(*env, ctx->value);
        func_00297E58(*code, *env);
        func_002B2030(a);
        int *pb = b;
        int thread = a[0];
        func_002A7A30(pb);
        hThread__execCode(dst, thread, code, pb, 0, 0);
        func_002A75A8(pb, 2);
        func_002B1578(a, 2);
    }
    return dst;
}
