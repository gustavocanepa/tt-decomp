/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot { int state; char pad[0x418]; };
struct Obj { char pad[0x24]; Slot slots[2]; int cur; int unk85c; int done; };
extern "C" void func_00482EE0(Obj *) throw();
extern "C" void func_00483A10(Obj *) throw();
extern "C" int func_00485450(Obj *self) {
    if (self->done) return 1;
    Slot *s = &self->slots[1 - self->cur];
    switch (s->state) {
    case 0:
        s->state = 1;
        func_00483A10(self);
        return 1;
    case 1:
    case 2:
        func_00482EE0(self);
        s->state = 0;
        break;
    }
    return 1;
}
