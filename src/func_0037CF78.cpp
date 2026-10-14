struct VEntry { short delta; short index; void (*fn)(void *, int *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
struct Root { char pad[0x84]; Obj *race; };
extern "C" Root *D_005846B4;

extern "C" void func_0037CF78(int unused, int *arg1) {
    Obj *self = D_005846B4->race;
    VEntry *entry = (VEntry *)((char *)self->vtbl + 0x1F0);
    entry->fn((char *)self + entry->delta, arg1);
}
