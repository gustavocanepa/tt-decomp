struct VEntry { short delta; short index; void (*fn)(void *, int *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
struct Root { char pad[0x84]; Obj *race; };
extern "C" Root *D_005846B4;

extern "C" void func_0037CCB0(int unused, int *arg1) {
    Obj *self = D_005846B4->race;
    VEntry *entry = (VEntry *)((char *)self->vtbl + 0x1C0);
    entry->fn((char *)self + entry->delta, arg1);
}
