/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[12]; char *inner; };
extern "C" void func_0029FC50(char *, int, __builtin_va_list);
extern "C" void func_001C1098(Obj *o, int fmt, ...) {
    __builtin_va_list ap;
    __builtin_stdarg_start(ap, fmt);
    func_0029FC50(o->inner, fmt, ap);
}
