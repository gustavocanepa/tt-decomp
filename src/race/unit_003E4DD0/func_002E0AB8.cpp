/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[8]; void *head; };
extern "C" int func_002E0800(void *) throw();
extern "C" int func_002E0AB8(Obj *s) {
    void *p = s->head;
    if (!p) return 0;
    return func_002E0800(p);
}
