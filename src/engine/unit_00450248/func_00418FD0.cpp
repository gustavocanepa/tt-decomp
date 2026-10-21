/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Sub {
    char pad[0x18];
    s32 f18;
};

struct Self {
    char pad[0x1C];
    Sub *f1C;
    s32 f20;
};

struct Vec4 {
    f32 x, y, z, w;
};

extern "C" int func_00467728(void *);
extern "C" void func_0046AC38(s32);
extern "C" void func_0046AE40(s32);
extern "C" void func_0046AE88(s32);
extern "C" void func_0046AEA0(void);
extern "C" void func_0046BED0(void);
extern "C" void func_0046F0F8(s32);
extern "C" int func_004701C0(s32);
extern "C" void func_00470220(s32, f32);
extern "C" void func_00470298(s32);
extern "C" void func_004702D8(s32, float);
extern "C" void func_00478C98(s32);

extern Vec4 D_00769CD0;

extern "C" void func_00418FD0(Self *self) {
    u128 r0, r1, r2, t0, t1, t2, t3;
    Vec4 *v;
    f32 inv;

    if (self == 0)
        return;
    func_0046F0F8(0x11);
    func_00478C98(0xF);
    func_0046F0F8(2);
    func_0046F0F8(8);
    func_0046F0F8(5);
    func_0046F0F8(4);
    func_00478C98(3);
    func_0046F0F8(6);
    func_004701C0(3);
    func_00470220(4, 1.0f);
    func_00470298(1);
    func_004702D8(0x44, 0.0f);

    __asm__ volatile("vnop");
    __asm__ volatile("vmr32.xyzw $vf5, $vf0");
    __asm__ volatile("vmr32.xyzw $vf6, $vf5");
    func_0046BED0();
    __asm__ volatile("vsub.xyz $vf23, $vf0, $vf23");
    __asm__ volatile("qmfc2.ni %0, $vf20" : "=r"(r0));
    __asm__ volatile("qmfc2.ni %0, $vf21" : "=r"(r1));
    __asm__ volatile("qmfc2.ni %0, $vf22" : "=r"(r2));
    __asm__ volatile("pextlw %0, %1, %2" : "=r"(t0) : "r"(r1), "r"(r0));
    __asm__ volatile("pextuw %0, %1, %2" : "=r"(t1) : "r"(r1), "r"(r0));
    __asm__ volatile("pextlw %0, $0, %1" : "=r"(t2) : "r"(r2));
    __asm__ volatile("pextuw %0, $0, %1" : "=r"(t3) : "r"(r2));
    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(r0) : "r"(t2), "r"(t0));
    __asm__ volatile("pcpyud %0, %1, %2" : "=r"(r1) : "r"(t0), "r"(t2));
    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(r2) : "r"(t3), "r"(t1));
    __asm__ volatile("qmtc2.ni %0, $vf20" : : "r"(r0));
    __asm__ volatile("qmtc2.ni %0, $vf21" : : "r"(r1));
    __asm__ volatile("qmtc2.ni %0, $vf22" : : "r"(r2));
    __asm__ volatile("vmulax.xyz ACC, $vf20, $vf23x");
    __asm__ volatile("vmadday.xyz ACC, $vf21, $vf23y");
    __asm__ volatile("vmaddz.xyz $vf23, $vf22, $vf23z");
    __asm__ volatile("vmulax.xyzw ACC, $vf20, $vf5x");
    __asm__ volatile("vmadday.xyzw ACC, $vf21, $vf5y");
    __asm__ volatile("vmaddz.xyzw $vf5, $vf22, $vf5z");
    __asm__ volatile("vopmula.xyz ACC, $vf6, $vf5");
    __asm__ volatile("vopmsub.xyz $vf7, $vf5, $vf6");
    v = &D_00769CD0;
    __asm__ volatile("sqc2 $vf7, %0" : "=m"(*v));
    __asm__("rsqrt.s %0, %2, %1" : "=f"(inv) : "f"(v->x * v->x + v->z * v->z), "f"(1.0f));
    v->x *= inv;
    v->z *= inv;

    func_00467728(self->f1C);
    func_0046AC38((s32)func_0046AEA0);
    func_0046AE88(self->f1C->f18);
    func_0046AE40(self->f20);
}
