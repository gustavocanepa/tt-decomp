struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0022F6A0(struct Derived *self);
extern "C" char D_005B3CB8[];
extern "C" struct Derived *func_00211C00(struct Derived *self)
{
    struct Derived *r = func_0022F6A0(self);
    self->vtbl = D_005B3CB8;
    return r;
}
