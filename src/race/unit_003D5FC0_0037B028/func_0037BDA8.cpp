/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { int w[24]; };
struct Src { char pad[0x50]; Blk b; };
struct Rep {
    char pad0[0xB8];
    Blk b;
    char pad1[0x138 - 0xB8 - 0x60 - 4];
    void *f12C;
    Src *f130;
};
extern char D_005D41F0[];
extern "C" int RaceInformation__structor_0(Rep *);
extern "C" void func_003703A0(Rep *, long);
extern "C" long func_0037BF10(Rep *);

extern "C" void func_0037BDA8(Rep *self, Src *src) {
    RaceInformation__structor_0(self);
    self->f12C = D_005D41F0;
    self->f130 = src;
    func_003703A0(self, func_0037BF10(self));
    self->b = src->b;
}
