struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_001D3760(struct Derived *self);
extern "C" char D_005B05A8[];
extern "C" struct Derived *func_001D7430(struct Derived *self)
{
    struct Derived *r = func_001D3760(self);
    self->vtbl = D_005B05A8;
    return r;
}
