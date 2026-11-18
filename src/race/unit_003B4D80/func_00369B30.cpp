/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { short delta, index; void (*fn)(void *); };
struct Owner { void *p0; void *p4; char *vt; };
struct Self {
    char pad0[0x18];
    void *p18;
    char pad1[0x12C0 - 0x1C];
    Owner embedded;
    char pad2[0x4840 - 0x12C0 - sizeof(Owner)];
    Owner *owner;
    char pad3[0xC];
    char data[4];
};
extern "C" void func_00369B30(Self *self) {
    Owner *o = self->owner;
    if (o) {
        Ent *e = (Ent *)(o->vt + 0x18);
        e->fn((char *)o + e->delta);
    }
    self->owner = &self->embedded;
    self->owner->p0 = self->data;
    self->owner->p4 = self->p18;
}
