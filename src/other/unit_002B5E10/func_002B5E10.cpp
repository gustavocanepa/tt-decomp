struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002B2290(struct Derived *self);
extern "C" char D_005C6940[];
extern "C" struct Derived *func_002B5E10(struct Derived *self)
{
    struct Derived *r = func_002B2290(self);
    self->vtbl = D_005C6940;
    return r;
}
