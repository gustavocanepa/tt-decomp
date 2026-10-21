/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int mode; char pad[0x418]; };
struct Obj { char pad[0x24]; State state[2]; int index; int pad85c; int busy; };
extern "C" int func_00482300(Obj *, int) throw();
extern "C" void func_00482EE0(Obj *) throw();
extern "C" void func_00483998(Obj *, int) throw();
extern "C" void func_00483A10(Obj *) throw();
extern "C" void func_00485D88(Obj *, int);
extern "C" int func_00484758(Obj *self) {
    if (self->busy) return 1;
    State *s = &self->state[1-self->index];
    switch (s->mode) {
    case 0:
        func_00483998(self, 10);
        func_00485D88(self, 0);
        return 1;
    case 1:
        if (func_00482300(self, 1) <= 0) {
        func_00482EE0(self);
        s->mode = 0;
        func_00483998(self, 10);
        s->mode = 1;
        func_00483A10(self);
        return 1;
        }
        return 0;
    case 2:
        return 0;
    default:
        return 1;
    }
}
