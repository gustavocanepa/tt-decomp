struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002A7618(struct Derived *self);
extern "C" char D_005A4F40[];
extern "C" struct Derived *func_00117420(struct Derived *self)
{
    struct Derived *r = func_002A7618(self);
    self->vtbl = D_005A4F40;
    return r;
}
