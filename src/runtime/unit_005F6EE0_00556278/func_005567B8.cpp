struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00358B80(struct Derived *self);
extern "C" char D_005CFB28[];
extern "C" struct Derived *func_005567B8(struct Derived *self)
{
    struct Derived *r = func_00358B80(self);
    self->vtbl = D_005CFB28;
    return r;
}
