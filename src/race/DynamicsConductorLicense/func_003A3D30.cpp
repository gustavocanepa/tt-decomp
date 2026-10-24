/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, int, float, int, int); };
struct Self { char pad[0x241CC]; VEntry *vtbl; };
struct Entrant { char pad[0x77B]; unsigned char flag; };
extern "C" Entrant *func_002F04D8(Self *, int);
extern "C" void func_003A3D30(Self *self, int a, float f, int b, int c) {
    func_002F04D8(self, a)->flag = 0;
    VEntry *e = &self->vtbl[20];
    e->fn((char *)self + e->delta, a, f, b, c);
}
