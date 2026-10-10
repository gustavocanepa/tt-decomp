struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00194908(struct Derived *self);
extern "C" char D_005AB5A0[];
extern "C" struct Derived *func_00194DD0(struct Derived *self)
{
    struct Derived *r = func_00194908(self);
    self->vtbl = D_005AB5A0;
    return r;
}
