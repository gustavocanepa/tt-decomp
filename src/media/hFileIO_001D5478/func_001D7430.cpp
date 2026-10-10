struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mNetConf__structor_1(struct Derived *self);
extern "C" char D_005B05A8[];
extern "C" struct Derived *func_001D7430(struct Derived *self)
{
    struct Derived *r = mNetConf__structor_1(self);
    self->vtbl = D_005B05A8;
    return r;
}
