struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002C0EB0(struct Derived *self);
extern "C" char D_005C65F8[];
extern "C" struct Derived *func_002B7320(struct Derived *self)
{
    struct Derived *r = func_002C0EB0(self);
    self->vtbl = D_005C65F8;
    return r;
}
