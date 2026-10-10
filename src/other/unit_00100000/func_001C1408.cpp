struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0022C018(struct Derived *self);
extern "C" char D_005AF290[];
extern "C" struct Derived *func_001C1408(struct Derived *self)
{
    struct Derived *r = func_0022C018(self);
    self->vtbl = D_005AF290;
    return r;
}
