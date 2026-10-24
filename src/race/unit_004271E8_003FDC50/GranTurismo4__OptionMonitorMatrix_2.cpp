typedef float f32; typedef int s32;
struct Fields { float unk0, unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C; };
static inline float root(float x) { float y; __asm__("sqrt.s %0, %1" : "=f"(y) : "f"(x)); return y; }
extern "C" f32 func_004A5B78(f32, f32);                        /* extern */
extern "C" f32 func_004A5C50(f32);                             /* extern */
extern "C" f32 func_004A5D18(f32) throw();                             /* extern */

extern "C" Fields *GranTurismo4__OptionMonitorMatrix_2(Fields *arg0, Fields *arg1, s32 arg2, s32 arg3, int arg4, int arg5) {
    f32 var_f29;
    f32 sp0;
    f32 sp4;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f30;
    f32 temp_f31;
    f32 temp_f9;
    f32 var_f12;
    f32 var_f22;
    f32 var_f25;
    f32 var_f26;
    f32 var_f27;
    f32 var_f28;
    f32 var_f8;

    var_f29 = 0.0f;
    var_f25 = 1.0f;
    var_f27 = 0.0f;
    var_f22 = 0.0f;
    var_f26 = 1.0f;
    var_f28 = 0.0f;
    sp0 = arg1->unkC * 0x1.0624dcp-10f;
    sp4 = arg1->unk10 * 0x1.0624dcp-10f;
    temp_f23 = arg1->unk14;
    temp_f21 = arg1->unk8 * 0x1.0624dcp-10f;
    temp_f30 = arg1->unk18;
    temp_f31 = arg1->unk4;
    temp_f12 = (arg1->unk1C * 0x1.0624dcp-10f) + sp0 + (arg1->unk20 * 0x1.0624dcp-10f);
    temp_f24 = (arg1->unk24 * 0x1.0624dcp-10f) + sp4 + (arg1->unk28 * 0x1.0624dcp-10f);
    if (arg5 != 0) {
        temp_f20 = 2.0f * (func_004A5B78(temp_f12, 2.0f * temp_f21) * (f32) arg2);
        var_f25 = func_004A5C50(temp_f20);
        var_f22 = func_004A5D18(temp_f20);
    } else {
        var_f27 = temp_f12 * (f32) arg2;
    }
    if (arg4 != 0) {
        temp_f20_2 = 2.0f * (func_004A5B78(temp_f24, 2.0f * root((var_f27 * var_f27) + (temp_f21 * temp_f21))) * (f32) arg3);
        var_f26 = func_004A5C50(temp_f20_2);
        var_f28 = func_004A5D18(temp_f20_2);
    } else {
        var_f29 = temp_f24 * (f32) arg3;
    }
    temp_f1 = 2.0f * temp_f30;
    temp_f10 = temp_f1 / sp0;
    temp_f14 = temp_f1 / sp4;
    temp_f9 = var_f26 * var_f25;
    float p13 = var_f26 * var_f22;
    temp_f11 = var_f28 * var_f25;
    float p2 = var_f28 * var_f22;
    var_f8 = temp_f31;
    var_f12 = var_f8;
    if (temp_f23 >= 1.0f) {
        var_f12 = var_f8 / temp_f23;
    } else {
        var_f8 *= temp_f23;
    }
    arg0->unk0 = (f32) (temp_f10 * ((temp_f21 * var_f25) + (var_f27 * var_f22)) * var_f12);
    arg0->unk10 = (f32) (temp_f10 * ((-temp_f21 * p2) - (var_f27 * temp_f11)) * var_f8);
    arg0->unk20 = (f32) (temp_f10 * ((temp_f21 * p13) + (var_f27 * temp_f9)));
    arg0->unk30 = 0;
    arg0->unk4 = (f32) (temp_f14 * (-var_f29 * var_f22) * var_f12);
    arg0->unk14 = (f32) (temp_f14 * ((temp_f21 * var_f26) - (var_f29 * temp_f11)) * var_f8);
    arg0->unk24 = (f32) (temp_f14 * ((temp_f21 * var_f28) + (var_f29 * temp_f9)));
    arg0->unk34 = 0;
    arg0->unk8 = (f32) (-var_f22 * var_f12);
    arg0->unk18 = (f32) (-temp_f11 * var_f8);
    arg0->unk28 = temp_f9;
    arg0->unk38 = 0;
    arg0->unkC = 0;
    arg0->unk1C = 0;
    arg0->unk2C = 0;
    arg0->unk3C = 1.0f;
    return arg0;
}
