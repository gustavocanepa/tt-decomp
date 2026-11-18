/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern "C" void func_003CD750(float (*)[4],float,float,float) throw();
extern "C" void func_003CD860(float (*)[4], const float *,float *) throw();
extern "C" void func_003CD8B8(float (*)[4], const float *,float *) throw();
extern "C" void func_004A6328(float,float *,float *);
extern "C"
s32 func_003CD9F0(void *arg0, f32 fparg0) {
    struct StackFrame { float force[4]; float torque[4]; float m[4][4]; float local[4]; float scaled[4]; float sp80,sp84,sp88,sp8C; } sp_;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f24;
    f32 temp_f25;
    f32 temp_f26;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f1;
    s32 var_v0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1;

    temp_v0 = M2C_FIELD(arg0, void **, 0x4C);
    temp_f24 = M2C_FIELD(arg0, f32 *, 0x2C);
    temp_f20 = M2C_FIELD(temp_v0, f32 *, 0x18);
    temp_f21 = M2C_FIELD(temp_v0, f32 *, 0x1C);
    temp_f22 = M2C_FIELD(temp_v0, f32 *, 0x20);
    temp_f26 = M2C_FIELD(arg0, f32 *, 0x34);
    temp_f25 = M2C_FIELD(arg0, f32 *, 0x30);
    func_003CD750(sp_.m, M2C_FIELD(arg0, f32 *, 8), M2C_FIELD(arg0, f32 *, 0xC), M2C_FIELD(arg0, f32 *, 0x10));
    func_003CD8B8(sp_.m, (float *)((char *)arg0 + 0x20), &sp_.local[0]);
    temp_v0_2 = M2C_FIELD(arg0, void **, 0x4C);
    sp_.scaled[0] = M2C_FIELD(temp_v0_2, f32 *, 0x28) * sp_.local[0];
    sp_.scaled[1] = M2C_FIELD(temp_v0_2, f32 *, 0x24) * sp_.local[1];
    sp_.scaled[2] = M2C_FIELD(temp_v0_2, f32 *, 0x28) * sp_.local[2];
    func_003CD860(sp_.m, &sp_.scaled[0], sp_.force);
    temp_v0_3 = M2C_FIELD(arg0, void **, 0x4C);
    sp_.force[1] += -M2C_FIELD(temp_v0_3, f32 *, 4) * 0x1.39eb840000000p+3f;
    sp_.torque[0] = M2C_FIELD(temp_v0_3, f32 *, 0x2C) * temp_f24;
    sp_.torque[1] = 0x0.0p+0f;
    sp_.torque[2] = M2C_FIELD(temp_v0_3, f32 *, 0x30) * temp_f26;
    func_004A6328(M2C_FIELD(arg0, f32 *, 8), &sp_.sp80, &sp_.sp84);
    func_004A6328(M2C_FIELD(arg0, f32 *, 0x10), &sp_.sp88, &sp_.sp8C);
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) + (((sp_.torque[0] + ((temp_f21 - temp_f22) * temp_f25 * temp_f26)) * fparg0) / temp_f20));
    M2C_FIELD(arg0, f32 *, 0x30) = (f32) (M2C_FIELD(arg0, f32 *, 0x30) + (((sp_.torque[1] + ((temp_f22 - temp_f20) * temp_f26 * temp_f24)) * fparg0) / temp_f21));
    M2C_FIELD(arg0, f32 *, 0x34) = (f32) (M2C_FIELD(arg0, f32 *, 0x34) + (((sp_.torque[2] + ((temp_f20 - temp_f21) * temp_f24 * temp_f25)) * fparg0) / temp_f22));
    if (sp_.sp84 != 0x0.0p+0f) {
        temp_f1 = ((temp_f24 * sp_.sp88) - (temp_f25 * sp_.sp8C)) / sp_.sp84;
        M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + (-((temp_f24 * sp_.sp8C) + (temp_f25 * sp_.sp88)) * fparg0));
        M2C_FIELD(arg0, f32 *, 0xC) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + (temp_f1 * fparg0));
        M2C_FIELD(arg0, f32 *, 0x10) = (f32) (M2C_FIELD(arg0, f32 *, 0x10) + (-((temp_f1 * sp_.sp80) + temp_f26) * fparg0));
    }
    var_f1 = M2C_FIELD(arg0, f32 *, 8);
    if (var_f1 < 0x0.0p+0f) {
        temp_f0 = var_f1 + 0x1.921fb40000000p+2f;
        M2C_FIELD(arg0, f32 *, 8) = temp_f0;
        var_f1 = temp_f0;
    }
    if (var_f1 >= 0x1.921fb40000000p+2f) {
        M2C_FIELD(arg0, f32 *, 8) = (f32) (var_f1 - 0x1.921fb40000000p+2f);
    }
    var_f0 = M2C_FIELD(arg0, f32 *, 0xC);
    if (var_f0 < 0x0.0p+0f) {
        var_f0 += 0x1.921fb40000000p+2f;
        M2C_FIELD(arg0, f32 *, 0xC) = var_f0;
    }
    if (var_f0 >= 0x1.921fb40000000p+2f) {
        M2C_FIELD(arg0, f32 *, 0xC) = (f32) (var_f0 - 0x1.921fb40000000p+2f);
    }
    var_f0_2 = M2C_FIELD(arg0, f32 *, 0x10);
    if (var_f0_2 < 0x0.0p+0f) {
        var_f0_2 += 0x1.921fb40000000p+2f;
        M2C_FIELD(arg0, f32 *, 0x10) = var_f0_2;
    }
    if (var_f0_2 >= 0x1.921fb40000000p+2f) {
        M2C_FIELD(arg0, f32 *, 0x10) = (f32) (var_f0_2 - 0x1.921fb40000000p+2f);
    }
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) (M2C_FIELD(arg0, f32 *, 0x14) + (M2C_FIELD(arg0, f32 *, 0x20) * fparg0));
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) (M2C_FIELD(arg0, f32 *, 0x18) + (M2C_FIELD(arg0, f32 *, 0x24) * fparg0));
    M2C_FIELD(arg0, f32 *, 0x1C) = (f32) (M2C_FIELD(arg0, f32 *, 0x1C) + (M2C_FIELD(arg0, f32 *, 0x28) * fparg0));
    M2C_FIELD(arg0, f32 *, 0x20) = (f32) (M2C_FIELD(arg0, f32 *, 0x20) + (sp_.force[0] * M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), f32 *, 0x10) * fparg0));
    temp_v1 = M2C_FIELD(arg0, void **, 0x4C);
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) (M2C_FIELD(arg0, f32 *, 0x24) + (sp_.force[1] * M2C_FIELD(temp_v1, f32 *, 0x10) * fparg0));
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + (sp_.force[2] * M2C_FIELD(temp_v1, f32 *, 0x10) * fparg0));
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) * 0x1.ff7cec0000000p-1f);
    M2C_FIELD(arg0, f32 *, 0x30) = (f32) (M2C_FIELD(arg0, f32 *, 0x30) * 0x1.ff7cec0000000p-1f);
    M2C_FIELD(arg0, f32 *, 0x34) = (f32) (M2C_FIELD(arg0, f32 *, 0x34) * 0x1.ff7cec0000000p-1f);
    if (((M2C_FIELD(arg0, f32 *, 0x38) * M2C_FIELD(arg0, f32 *, 0x14)) + (M2C_FIELD(arg0, f32 *, 0x3C) * M2C_FIELD(arg0, f32 *, 0x18)) + (M2C_FIELD(arg0, f32 *, 0x40) * M2C_FIELD(arg0, f32 *, 0x1C)) + M2C_FIELD(arg0, f32 *, 0x44)) < 0x0.0p+0f) {
        return 0;
    }
    return 1;
}
