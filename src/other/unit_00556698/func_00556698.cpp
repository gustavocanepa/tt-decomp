struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00358B80(struct Derived *self);
extern "C" char D_005CFB78[];
extern "C" struct Derived *func_00556698(struct Derived *self)
{
    struct Derived *r = func_00358B80(self);
    self->vtbl = D_005CFB78;
    return r;
}
