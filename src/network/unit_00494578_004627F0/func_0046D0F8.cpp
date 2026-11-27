/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

union Vec {
    u128 q;
    struct {
        f32 x, y, z, w;
    } v;
};

extern f32 D_00587268;
extern f32 D_0076E7C0[3][4];
extern f32 D_0076E7F0[4];
extern f32 D_0076E800[4];
extern f32 D_0076E810[4];
extern f32 D_0076E820[4];
extern f32 D_0076E830[4];
extern f32 D_0076E840[4];

extern "C" f32 func_00473D58(f32 y, f32 x);
extern "C" void func_004751E0(f32 deg);

/* Turns the eye direction into view space, derives the roll angle from it and rebuilds the matrices. */
extern "C" void func_0046D0F8(f32 x, f32 y, f32 z) {
    Vec dir;

    __asm__ volatile("vnop");
    dir.v.x = x;
    dir.v.y = y;
    dir.v.z = z;
    __asm__ volatile("lqc2 $vf9, %0" : : "m"(dir.q));
    __asm__ volatile("lqc2 $vf1, %0" : : "m"(D_0076E7F0[0]));
    __asm__ volatile("lqc2 $vf2, %0" : : "m"(D_0076E800[0]));
    __asm__ volatile("lqc2 $vf3, %0" : : "m"(D_0076E810[0]));
    __asm__ volatile("vmulax.xyzw ACC, $vf1, $vf9x");
    __asm__ volatile("vmadday.xyzw ACC, $vf2, $vf9y");
    __asm__ volatile("vmaddz.xyzw $vf9, $vf3, $vf9z");
    __asm__ volatile("sqc2 $vf9, %0" : "=m"(dir.q));
    f32 *roll = &D_00587268;
    *roll = -((func_00473D58(dir.v.z, dir.v.x) + 1.0f) * 0.125f);
    func_004751E0(*roll * -360.0f);
    __asm__ volatile("vaddy.x $vf4, $vf0, $vf1y");
    __asm__ volatile("vadd.y $vf4, $vf0, $vf0");
    __asm__ volatile("vsubx.z $vf4, $vf0, $vf1x");
    __asm__ volatile("vadd.xz $vf5, $vf0, $vf0");
    __asm__ volatile("vaddw.y $vf5, $vf0, $vf0w");
    __asm__ volatile("vaddx.x $vf6, $vf0, $vf1x");
    __asm__ volatile("vadd.y $vf6, $vf0, $vf0");
    __asm__ volatile("vaddy.z $vf6, $vf0, $vf1y");
    __asm__ volatile("lqc2 $vf1, %0" : : "m"(D_0076E7F0[0]));
    __asm__ volatile("lqc2 $vf2, %0" : : "m"(D_0076E800[0]));
    __asm__ volatile("lqc2 $vf3, %0" : : "m"(D_0076E810[0]));
    __asm__ volatile("vmulax.xyzw ACC, $vf4, $vf1x");
    __asm__ volatile("vmadday.xyzw ACC, $vf5, $vf1y");
    __asm__ volatile("vmaddz.xyzw $vf1, $vf6, $vf1z");
    __asm__ volatile("vmulax.xyzw ACC, $vf4, $vf2x");
    __asm__ volatile("vmadday.xyzw ACC, $vf5, $vf2y");
    __asm__ volatile("vmaddz.xyzw $vf2, $vf6, $vf2z");
    __asm__ volatile("vmulax.xyzw ACC, $vf4, $vf3x");
    __asm__ volatile("vmadday.xyzw ACC, $vf5, $vf3y");
    __asm__ volatile("vmaddz.xyzw $vf3, $vf6, $vf3z");
    __asm__ volatile("lqc2 $vf4, %0" : : "m"(D_0076E820[0]));
    __asm__ volatile("lqc2 $vf5, %0" : : "m"(D_0076E830[0]));
    __asm__ volatile("lqc2 $vf6, %0" : : "m"(D_0076E840[0]));
    __asm__ volatile("vmulax.xyzw ACC, $vf1, $vf4x");
    __asm__ volatile("vmadday.xyzw ACC, $vf2, $vf4y");
    __asm__ volatile("vmaddz.xyzw $vf4, $vf3, $vf4z");
    __asm__ volatile("vmulax.xyzw ACC, $vf1, $vf5x");
    __asm__ volatile("vmadday.xyzw ACC, $vf2, $vf5y");
    __asm__ volatile("vmaddz.xyzw $vf5, $vf3, $vf5z");
    __asm__ volatile("vmulax.xyzw ACC, $vf1, $vf6x");
    __asm__ volatile("vmadday.xyzw ACC, $vf2, $vf6y");
    __asm__ volatile("vmaddz.xyzw $vf6, $vf3, $vf6z");
    __asm__ volatile("sqc2 $vf4, %0" : "=m"(*(u128 *)D_0076E7C0[0]));
    __asm__ volatile("sqc2 $vf5, %0" : "=m"(*(u128 *)D_0076E7C0[1]));
    __asm__ volatile("sqc2 $vf6, %0" : "=m"(*(u128 *)D_0076E7C0[2]));
}
