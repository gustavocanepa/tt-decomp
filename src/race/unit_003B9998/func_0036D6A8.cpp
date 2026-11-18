/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern char D_005D1AB0[];
extern char D_005D6380[];
extern "C" {
void func_00389110(void *, int);
static inline void destroyArr(char *base) {
    if (base != 0) {
        char *e = base + 0x30;
        if (base != e) {
            do {
                e -= 8;
                func_00389110(e, 2);
            } while (base != e);
        }
    }
}
void DynamicsConductor__structor_1(void *, s32);
void func_00389110(void *, int);
void func_0034F970(void *, s32);
void RacePause__structor_1(void *, s32);
void RaceFuelMeter__structor_2(void *, s32);
void func_00379B08(void *, s32);
void func_00386198(void *, s32);
void func_0050E1A8(void *) throw();
void func_0036D6A8(char *self, s32 flags) {
    char *base = self + 0x33470;
    *(char **)(self + 0x64) = D_005D1AB0;
    func_00379B08(self + 0x39CD8, 2);
    RaceFuelMeter__structor_2(self + 0x38994, 2);
    func_0034F970(self + 0x334D8, 2);
    RacePause__structor_1(self + 0x334A0, 2);
    destroyArr(base);
    char *v = self + 0xF280;
    *(char **)(v + 0x241CC) = D_005D6380;
    DynamicsConductor__structor_1(v, 0);
    func_00386198(self, 0);
    if (flags & 1)
        return func_0050E1A8(self);
}
}
