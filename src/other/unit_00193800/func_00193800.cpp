struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002A7618(struct Derived *self);
extern "C" char D_005AAD28[];
extern "C" struct Derived *func_00193800(struct Derived *self)
{
    struct Derived *r = func_002A7618(self);
    self->vtbl = D_005AAD28;
    return r;
}
