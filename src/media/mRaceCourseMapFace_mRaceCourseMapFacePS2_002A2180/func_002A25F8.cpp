struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002BC190(struct Derived *self);
extern "C" char D_005C52A0[];
extern "C" struct Derived *func_002A25F8(struct Derived *self)
{
    struct Derived *r = func_002BC190(self);
    self->vtbl = D_005C52A0;
    return r;
}
