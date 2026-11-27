/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x64]; void *vt; };
extern char D_005CF078[];
extern char D_005D45D0[];
extern char D_005C92A0[];
extern "C" void func_00379B08(void *, int);
extern "C" void RaceFuelMeter__structor_2(void *, int);
extern "C" void RacePause__structor_1(void *, int);
extern "C" void func_0037D460(void *, int);
extern "C" void func_00389110(void *, int);
extern "C" void DynamicsConductor__structor_1(void *, int);
extern "C" void RaceSinglePlayer__structor_1(void *, int);
extern "C" void func_0050E1A8(void *) throw();
extern "C" void DynamicsConductorSinglePlayer__structor_6(Obj *o, int flags) {
    char *begin = (char *)o + 0x37DD0;
    o->vt = D_005CF078;
    func_00379B08((char *)o + 0x399E8, 2);
    RaceFuelMeter__structor_2((char *)o + 0x386A8, 2);
    RacePause__structor_1((char *)o + 0x38670, 2);
    char *e = (char *)o + 0x37E00;
    *(void **)(e + 0x18) = D_005D45D0;
    func_0037D460(e, 0);
    if (begin) {
        char *p = begin + 0x30;
        if (begin != p) {
            do {
                p -= 8;
                func_00389110(p, 2);
            } while (begin != p);
        }
    }
    char *q = (char *)o + 0x13C00;
    *(void **)(q + 0x241CC) = D_005C92A0;
    DynamicsConductor__structor_1(q, 0);
    RaceSinglePlayer__structor_1(o, 0);
    if (flags & 1) return func_0050E1A8(o);
}
