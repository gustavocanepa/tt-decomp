struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_002A7618(struct Derived *self);
extern "C" char D_005BE4D0[];
extern "C" struct Derived *func_0026E4C8(struct Derived *self)
{
    struct Derived *r = func_002A7618(self);
    self->vtbl = D_005BE4D0;
    return r;
}
