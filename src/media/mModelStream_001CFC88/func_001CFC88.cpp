struct S { char pad[0x28]; struct P { char pad[0x10]; int v; } *p; };
extern "C" void func_001B1B58(S *, int);
extern "C" void func_001CFC88(S *s) {
    if (s->p) return func_001B1B58(s, s->p->v);
    func_001B1B58(s, 0);
}
