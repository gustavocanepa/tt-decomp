/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Args { float f; int a, b; };
extern "C" void func_0042B678(void *, int, int, float);
extern "C" void func_0042B9D0(int);
extern "C" void func_0042CC68(void *, int, int, float);
static inline int dispatch(int mode, void *obj, int b, int a, float f) {
    switch (mode) {
    case -1: func_0042CC68(obj, b, a, f); return 1;
    case -2: func_0042B678(obj, b, a, f); return 2;
    case -3: func_0042B9D0((int)obj); return 3;
    default: return 0;
    }
}
extern "C" int func_0042BB68(int mode, void *obj, Args *p) {
    return dispatch(mode, obj, p->b, p->a, p->f);
}
