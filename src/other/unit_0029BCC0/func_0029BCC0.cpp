struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002BC190(struct Derived *self);
extern "C" char D_005C4700[];
extern "C" struct Derived *func_0029BCC0(struct Derived *self)
{
    struct Derived *r = func_002BC190(self);
    self->vtbl = D_005C4700;
    return r;
}
