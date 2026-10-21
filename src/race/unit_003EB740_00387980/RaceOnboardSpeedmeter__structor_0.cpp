/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self {
 char pad0[0x14]; void *vt; char pad18[0x10];
 unsigned color28, color2c; float f30; signed char mode; char pad35[0x1b]; float f50, f54;
};
extern char D_005D4D68[];
extern "C" void *RaceRoundMeterBase__structor_0(Self *);
extern "C" void func_003BE228(Self *, float, float);
extern "C" void func_00391E68(Self *, float, float);
extern "C" void func_00391E78(Self *, float, float);
extern "C" void func_00391E88(Self *, float, float);
extern "C" int RaceOnboardSpeedmeter__structor_0(Self *self) {
 RaceRoundMeterBase__structor_0(self);
 self->vt = D_005D4D68;
 float one = 1.0f;
 func_00391E68(self, one, 15.0f);
 func_00391E78(self, 60.0f, one);
 func_00391E88(self, 56.0f, 276.0f);
 self->f50 = -0x1.3d21fep-2f;
 self->f54 = 0x1.ec2f82p-1f;
 self->mode = 5;
 self->color28 = 0x80000000;
 self->color2c = 0x80ffffff;
}
