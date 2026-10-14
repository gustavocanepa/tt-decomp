/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))

extern "C" void RaceFuelMeter__structor_1(void *);                      /* extern */
extern "C" void RaceTireWearDisplay__structor_1(void *);                      /* extern */
extern "C" void RaceTooltipDisplay__structor_0(void *);                      /* extern */
extern "C" int RaceMiniMap__structor_1(void *);                         /* extern */
extern "C" void func_003F5338(void *);                      /* extern */

struct Obj {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    float f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
};
extern "C" void func_002D6A80(Obj *arg0) {
    arg0->f0 = 0;
    arg0->f4 = 0;
    arg0->f8 = 0;
    arg0->fc = 0;
    arg0->f10 = 0;
    arg0->f14 = 0;
    arg0->f18 = 0;
    arg0->f1c = 0;
    arg0->f20 = 0;
    arg0->f24 = 0;
    arg0->f28 = 0;
    arg0->f2c = 0;
    arg0->f30 = 0;
    arg0->f34 = 0;
    arg0->f38 = 0;
    arg0->f3c = 0;
    arg0->f40 = 0;
    arg0->f44 = 1;
    arg0->f48 = 0;
    arg0->f4c = 0;
    arg0->f50 = 0;
    arg0->f54 = 0;
    arg0->f58 = 0;
    arg0->f5c = 0;
    arg0->f60 = 0;
    arg0->f64 = 0;
    arg0->f68 = 0;
    arg0->f6c = 0;
    arg0->f70 = 0;
    arg0->f74 = 1;
    arg0->f78 = 1;
    arg0->f7c = 0;
    arg0->f80 = 0;
    arg0->f84 = 1.0f;
    arg0->f88 = 0;
    arg0->f8c = 0;
    arg0->f90 = 0;
    arg0->f94 = 0;
    arg0->f98 = 0;
    arg0->f9c = -1;
    RaceMiniMap__structor_1((char *)arg0 + 0x298);
    RaceFuelMeter__structor_1((char *)arg0 + 0x300);
    RaceTireWearDisplay__structor_1((char *)arg0 + 0x328);
    RaceTooltipDisplay__structor_0((char *)arg0 + 0x358);
    return func_003F5338((char *)arg0 + 0x12B4);
}
