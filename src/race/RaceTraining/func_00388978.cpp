struct VEntry { short delta; short index; int (*fn)(void *, int *); };
struct Obj { void *f0; };
struct RT {
    char pad0[0x64];
    char *f64;
    char pad68[0xD8C - 0x68];
    int fCC8;
};
extern "C" void RaceTrainingBase__initialize(RT *) throw();
extern "C" void func_0033E078(RT *, char *);
extern "C" void func_0037FC78(char *, int, int, int);
extern "C" void func_0037FD10(char *, RT *);
extern "C" void RaceDisplay__virtual_06(char *, int);

extern "C" void func_00388978(RT *self) {
    int sp0;
    RaceTrainingBase__initialize(self);
    if ((unsigned)(self->fCC8 - 2) < 2)
        func_0033E078(self, 0);
    else
        func_0033E078(self, ((char *)self + 0x39000));
    VEntry *e = (VEntry *)(self->f64 + 0x310);
    int r = e->fn((char *)self + e->delta, &sp0);
    func_0037FC78(((char *)self + 0x39000), r, sp0, 0);
    func_0037FD10(((char *)self + 0x39000), self);
    RaceDisplay__virtual_06((char *)self + 0x39930, 3);
}
