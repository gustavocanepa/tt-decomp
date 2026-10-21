typedef int s32;
typedef float f32;

struct C {
    char pad[1];
};

struct Obj {
    char pad[1];
};

struct mSelectBox {
    char pad0[0xD4];
    s32 unkB0;      /* 0xB0 */
    char padB4[0xBC - 0xB4];
    char padBC[0xD4 - 0xBC];
    f32 unkD4;      /* 0xD4 */
    s32 unkD8;      /* 0xFC */
    char padDC[0xE4 - 0xDC];
    f32 unkE4;      /* 0xE4 */
    f32 unkE8;      /* 0x10C */
    f32 unkEC;      /* 0xEC */
};

extern "C" f32 func_00205D10(struct C *arg0);
extern "C" f32 func_00205D70(struct C *arg0);
extern "C" f32 func_00278870(Obj *arg0);
extern "C" s32 func_004AC5A0(Obj *arg0);

extern "C" f32 func_00279D08(struct mSelectBox *arg0) {
    Obj *sub;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f3;
    f32 temp2;
    f32 temp0;
    f32 var_f1;
    f32 var_f4;
    f32 var_f0_2;
    s32 t;
    s32 n;

    t = arg0->unkB0;
    if (t == 0) {
        f21 = arg0->unkE4;
    } else {
        f21 = arg0->unkE8;
    }
    if (t == 0) {
        f20 = func_00205D10((struct C *)arg0);
    } else {
        f20 = func_00205D70((struct C *)arg0);
    }
    f22 = f21 + func_00278870((Obj *)arg0);
    sub = (Obj *)((char *)arg0 + 0xE0);
    n = func_004AC5A0(sub) - 1;
    temp2 = f21 * arg0->unkD4;
    var_f1 = 0.0f;
    f3 = (f22 * (f32)n) + temp2;

    if (f3 < f20) {
        if (arg0->unkD8 == 0) {
            var_f1 = (f20 - f3) * 0x1.0p-1f;
        } else if (arg0->unkD8 == 1) {
            var_f1 = func_00278870((Obj *)arg0);
        }
    } else {
        temp2 = temp2 * 0x1.0p-1f;
        temp0 = (f22 * (f32)*(s32 *)sub) + temp2;
        var_f1 = (f20 * 0x1.0p-1f) - temp0;
        var_f4 = 0.0f;
        if (arg0->unkD8 == 0) {
            var_f4 = 0x1.333332p-2f;
        }
        temp0 = f21 * var_f4;
        if (temp0 < var_f1) {
            var_f1 = temp0;
        }
        var_f0_2 = (f20 - temp0) - f3;
        if (var_f1 < var_f0_2) {
            var_f1 = var_f0_2;
        }
    }
    return var_f1;
}
