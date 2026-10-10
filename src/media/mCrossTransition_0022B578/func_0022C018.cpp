struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002C0EB0(struct Derived *self);
extern "C" char D_005B7A20[];
extern "C" struct Derived *func_0022C018(struct Derived *self)
{
    struct Derived *r = func_002C0EB0(self);
    self->vtbl = D_005B7A20;
    return r;
}
