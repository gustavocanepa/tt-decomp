/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct Disp { char p[0x3C]; f32 f24; f32 f28; };
struct Obj {
    char p0[0x2B8]; int i2B8; f32 f2BC; char p1[0x2D4 - 0x2C0]; f32 f2D4, f2D8, f2DC, f2E0, f2E4;
    char p2[0x2F4 - 0x2E8]; f32 f2F4;
};
extern Disp *D_00586EF4;
extern char D_005E00A8[], D_005E00B0[], D_005E00B8[];
extern "C" {
void func_0045EC58(Disp *, char *);
void func_0045EEE0(Disp *, f32, f32, f32, f32);
f32 func_0045F220(Disp *);
void func_0045F2B8(Disp *, f32, f32);
int func_0045F378(Disp *, char *, ...);
void func_00475030(f32, f32, f32, f32, f32, f32);
int func_00478F40(f32, f32, f32);
}
extern "C" void func_0011A4E0(Obj *a, f32 fparg0) {
    f32 s = a->f2BC * 4.0f;
    f32 f24 = a->f2D4;
    f32 f29 = a->f2E0;
    int s5 = (int)(a->f2DC / s) + 1;
    int s0 = (int)(f24 / s);
    f32 f28 = a->f2D8;
    func_0045EC58(D_00586EF4, D_005E00A8);
    Disp *disp = D_00586EF4;
    disp->f28 = 0.5f;
    disp->f24 = 0.5f;
    s0 -= 1;
    f32 f0 = func_0045F220(D_00586EF4) - 1.0f;
    int i = s0;
    if (s5 >= i) {
        f32 f26 = fparg0 - f0;
        do {
            int pos = (int)((f32)i * a->f2BC * 4.0f);
            func_00478F40(0.5f, 0.5f, 0.5f);
            f32 f20 = (f32)pos;
            func_00475030(f20, f29, 0.0f, f20, f28, 0.0f);
            f20 -= f24;
            f20 *= a->f2E4;
            f32 f21 = a->f2F4;
            f21 -= f26;
            func_0045EEE0(D_00586EF4, 1.0f, 1.0f, 1.0f, 1.0f);
            func_0045F2B8(D_00586EF4, f20, f21);
            if (a->i2B8 != 0) {
                func_0045F378(D_00586EF4, D_005E00B0, pos);
            } else if ((i & 0xF) == 0) {
                func_0045F378(D_00586EF4, D_005E00B8, pos / 1600);
            }
            i++;
        } while (s5 >= i);
    }
}
