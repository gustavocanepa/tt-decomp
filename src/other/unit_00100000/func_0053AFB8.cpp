struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0022F6A0(struct Derived *self);
extern "C" char D_005B7DE0[];
extern "C" struct Derived *func_0053AFB8(struct Derived *self)
{
    struct Derived *r = func_0022F6A0(self);
    self->vtbl = D_005B7DE0;
    return r;
}
