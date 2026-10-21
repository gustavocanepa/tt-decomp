/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern char D_005CB720[];
extern char D_005C92A0[];

struct Slot { char b[8]; };
struct Res { char b[0x4F8]; };
struct Obj {
    char pad0[0x64];
    char *vt;
    char pad1[0x125C0 - 0x68];
    char blk[0x37DD0 - 0x125C0];
    Slot slots[6];
    Res res;
    char pad2[0x22C38 - 0x22738 - 0x4F8];
    char pause[0x38];
    char meter[0x23FB0 - 0x22C70];
};

extern "C" void DynamicsConductor__structor_1(void *, s32);
extern "C" void func_00389110(void *, int);
extern "C" void RacePause__structor_1(void *, int);
extern "C" void RaceSinglePlayer__structor_1(void *, s32);
extern "C" void RaceFuelMeter__structor_2(void *, int);
extern "C" void func_00379B08(void *, int);
extern "C" void func_0037D460(void *, int);
extern "C" void func_0050E1A8(void *) throw();

extern "C" void func_003391D8(Obj *self, s32 flags) {
    Slot *arr = self->slots;
    self->vt = D_005CB720;
    func_00379B08((char *)self + 0x39988, 2);
    RaceFuelMeter__structor_2((char *)self + 0x38644, 2);
    RacePause__structor_1((char *)self + 0x3860C, 2);
    func_0037D460((char *)self + 0x37E00, 2);
    if (arr != 0) {
        Slot *p = arr + 6;
        if (arr != p) {
            do {
                p--;
                func_00389110(p, 2);
            } while (arr != p);
        }
    }
    char *q = (char *)self + 0x13C00;
    *(char **)(q + 0x241CC) = D_005C92A0;
    DynamicsConductor__structor_1(q, 0);
    RaceSinglePlayer__structor_1(self, 0);
    if ((flags & 1) == 0) return;
    return func_0050E1A8(self);
}
