struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002A7650(struct Derived *self);
extern "C" char D_005C5858[];
extern "C" struct Derived *func_002A7410(struct Derived *self)
{
    struct Derived *r = func_002A7650(self);
    self->vtbl = D_005C5858;
    return r;
}
