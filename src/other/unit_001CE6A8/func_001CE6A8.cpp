struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0022C018(struct Derived *self);
extern "C" char D_005AFB40[];
extern "C" struct Derived *func_001CE6A8(struct Derived *self)
{
    struct Derived *r = func_0022C018(self);
    self->vtbl = D_005AFB40;
    return r;
}
