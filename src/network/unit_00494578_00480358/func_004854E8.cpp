/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x864]; int flag; };
extern "C" void *func_004834E8(Obj *) throw();
extern "C" int func_00485568(Obj *);
extern "C" int func_00485660(Obj *);
extern "C" int func_004854E8(Obj *obj) {
    if (obj->flag != 0) return 1;
    signed char c = *(signed char *)func_004834E8(obj);
    if (c == 3) return func_00485660(obj);
    if (c != 4) return func_00485568(obj);
    return func_00485660(obj);
}
