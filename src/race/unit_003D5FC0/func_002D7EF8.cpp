/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Car { char pad[0xD90]; int state; };
struct Holder { char pad[0x84]; Car *car; };
struct Obj { char pad0[4]; int enabled; char pad8[4]; Holder *holder; char pad10[8]; int car; char pad1c[0x20]; unsigned int mode; };
extern "C" int func_002D7EF8(Obj *self) {
    int result = 0;
    if (!self->car) return result;
    if (self->mode >= 2U) return result;
    if (!self->enabled) return result;
    Holder *h = self->holder;
    if (!h) return result;
    Car *c = h->car;
    if (c) return c->state == 1;
    return result;
}
