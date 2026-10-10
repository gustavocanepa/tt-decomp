struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00358B80(struct Derived *self);
extern "C" char D_005CFB50[];
extern "C" struct Derived *func_00556728(struct Derived *self)
{
    struct Derived *r = func_00358B80(self);
    self->vtbl = D_005CFB50;
    return r;
}
