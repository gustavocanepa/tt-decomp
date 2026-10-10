typedef int s32;

struct Obj {
    char pad0[0x64];
    void *vtbl;
};

extern char D_005D5308[];

extern "C" void RaceSinglePlayer__structor_1(Obj *self, int flags);
extern "C" void RacePause__structor_1(void *self, int flags);
extern "C" void func_0050E1A8(void *p);

extern "C" void RaceSplitBattle__structor_1(Obj *self, int flags) {
    self->vtbl = D_005D5308;
    RacePause__structor_1((char *)self + 0x13C00, 2);
    RaceSinglePlayer__structor_1(self, 0);
    if (flags & 1) {
        return func_0050E1A8(self);
    }
}
