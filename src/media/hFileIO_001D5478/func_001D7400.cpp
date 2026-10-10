struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_001D3728(struct Derived *self);
extern "C" char D_005B05A8[];
extern "C" struct Derived *func_001D7400(struct Derived *self)
{
    struct Derived *r = func_001D3728(self);
    self->vtbl = D_005B05A8;
    return r;
}
