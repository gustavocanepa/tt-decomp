struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002A7618(struct Derived *self);
extern "C" char D_005AA458[];
extern "C" struct Derived *func_00189D70(struct Derived *self)
{
    struct Derived *r = func_002A7618(self);
    self->vtbl = D_005AA458;
    return r;
}
