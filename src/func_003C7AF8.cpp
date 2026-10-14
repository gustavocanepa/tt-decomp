/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self {
 char pad0[0x14]; void *vt; char pad18[0x10];
 unsigned color28, color2c; float f30; signed char mode; char pad35[0x1b]; float f50, f54;
};
extern char D_005D7020[];
extern "C" void *RaceRoundMeterBase__structor_0(Self *);
extern "C" void func_00391890(Self *, float, float);
extern "C" void func_00391E68(Self *, float, float);
extern "C" void func_00391E78(Self *, float, float);
extern "C" void func_00391E88(Self *, float, float);
extern "C" int RaceBoostmeter__structor_0(Self *self) {
 RaceRoundMeterBase__structor_0(self);
 self->vt = D_005D7020;
 float z = 0.0f;
 func_00391890(self, z, 0x1.333332p+1f);
 func_00391E68(self, z, z);
 func_00391E78(self, 27.0f, 1.0f);
 func_00391E88(self, z, 0x1.affffep+7f);
 self->f50 = -0.5f;
 self->f54 = 0x1.b33332p-1f;
 self->mode = 5;
 self->color28 = 0x80000000;
 self->color2c = 0x80ffffff;
}
