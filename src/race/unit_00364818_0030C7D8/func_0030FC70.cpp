/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef short s16;
typedef float f32;

struct Dst {
    char pad0[0x30];
    f32 f30, f34, f38, f3C, f40, f44, f48, f4C, f50, f54, f58, f5C, f60, f64;
    char pad68;
    u8 b69;
};

extern u8 D_005836F0;
extern s16 D_005836F2;
extern s16 D_005836F4;
extern s16 D_005836F6;
extern s16 D_005836F8;
extern s16 D_005836FA;
extern s16 D_005836FC;
extern s16 D_005836FE;
extern s16 D_00583700;
extern u8 D_00583702;
extern u8 D_00583703;
extern u8 D_00583704;
extern u8 D_00583705;
extern u8 D_00583706;

extern "C" void func_0030FC70(Dst *d) {
    if (D_005836F0 != 0) {
        d->f30 = (f32)D_005836F2 * 0x1.0624dcp-10f;
        d->f34 = (f32)D_005836F4 * 0x1.0624dcp-10f;
        d->f38 = (f32)D_005836F6 * 0x1.0624dcp-10f;
        d->f3C = (f32)D_005836F8 * 0x1.0624dcp-10f;
        d->f40 = (f32)D_005836FA * 0x1.0624dcp-10f;
        d->f44 = (f32)D_005836FC * 0x1.0624dcp-10f;
        d->f48 = (f32)D_005836FE * 0x1.0624dcp-10f;
        d->f4C = (f32)D_00583700 * 0x1.0624dcp-10f * 0x1.abfd8p-14f;
        d->f50 = (f32)D_00583702 * -0x1.47ae14p-7f;
        d->f54 = (f32)D_00583703 * 0x1.47ae14p-7f;
        d->f58 = (f32)D_00583704 * 0x1.47ae14p-7f;
        d->f5C = (f32)D_00583705 * 0x1.47ae14p-7f;
        d->f60 = 1.0f;
        d->f64 = (f32)D_00583706 * 0x1.47ae14p-7f;
        d->b69 = 1;
    }
}
