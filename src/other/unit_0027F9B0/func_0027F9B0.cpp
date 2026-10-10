struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002A7618(struct Derived *self);
extern "C" char D_005C11E0[];
extern "C" struct Derived *func_0027F9B0(struct Derived *self)
{
    struct Derived *r = func_002A7618(self);
    self->vtbl = D_005C11E0;
    return r;
}
