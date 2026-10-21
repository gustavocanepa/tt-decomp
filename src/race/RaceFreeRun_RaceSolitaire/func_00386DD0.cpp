/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { char pad[0x64]; VEntry *vtbl; char pad68[0xE8FC-0x68]; int flag; };
extern "C" char *AutomobileControlRecord__Manager__load(void *, char *, int);
extern "C" void func_00386DD0(Obj *self, char *data) {
    AutomobileControlRecord__Manager__load((char *)self + 0xE620, data + 0x1A24, 1);
    VEntry *v = self->vtbl;
    self->flag = 1;
    VEntry *e = (VEntry *)((char *)v + 0x218);
    e->fn((char *)self + e->delta);
}
