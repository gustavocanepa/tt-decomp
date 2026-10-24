/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
extern "C" int AutomobileControlRecord__Manager__copyNormal(void *, void *);
extern "C" void func_003868E8(void *);
extern "C" void func_00386518(Obj *self) {
    char *ghost = (char *)self + 0xE90C;
    VEntry *e = &self->vtbl[161];
    e->fn((char *)self + e->delta);
    AutomobileControlRecord__Manager__copyNormal((char *)self + 0xE9E0, (char *)self + 0xE620);
    *(int *)(ghost + 0x1d0) = 0;
    func_003868E8(self);
}
