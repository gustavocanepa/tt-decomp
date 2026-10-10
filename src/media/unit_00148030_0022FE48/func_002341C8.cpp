struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mEvent__structor_0(struct Derived *self);
extern "C" char D_005B8820[];
extern "C" struct Derived *func_002341C8(struct Derived *self)
{
    struct Derived *r = mEvent__structor_0(self);
    self->vtbl = D_005B8820;
    return r;
}
