/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p0[0x18]; int state; char p1[0x2c]; unsigned short flags; char p2[0xad4]; short count; };
extern "C" void func_0046C138(Obj *) throw();
extern "C" void func_0046C220(Obj *) throw();
extern "C" void func_0046C3B8(Obj *) throw();
extern "C" void func_0046C630(Obj *, float);
extern "C" void func_0046C798(Obj *);
extern "C" void func_0046C8A0(Obj *);
extern "C" void func_0046CAD8(Obj *);
extern "C" void func_0046C520(Obj *p, float f) {
    if ((unsigned short)(p->flags & 1)) func_0046C798(p);
    if (p->flags & 2) func_0046C8A0(p);
    if (p->flags & 4) func_0046CAD8(p);
    if ((p->flags & 0x18) != 0x18) return func_0046C138(p);
    if (p->flags & 0x40) {
        if (p->count < 2) return func_0046C630(p, f);
        p->state = 0x16;
    } else {
        if (p->count < 3) return func_0046C3B8(p);
        return func_0046C220(p);
    }
}
