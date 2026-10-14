typedef float f32;
extern "C" void func_003F56C0(f32, f32, f32, f32);
extern "C" void func_003F5758(int, int, f32, f32, f32, f32);
extern "C" void func_00477DC0(int);
extern f32 D_005F95F8[];
extern f32 D_005F9610[];
struct Obj {
    char pad0[8];
    unsigned char n;
    unsigned char flag;
    char pad1;
    unsigned char sel;
    int p[4];
    f32 x1c, x20, x24, x28;
};
extern "C" void func_003F58E8(Obj *o) {
    f32 d = o->x28 - o->x20;
    f32 *t;
    int i;
    if (o->sel == 0) t = D_005F95F8; else t = D_005F9610;
    if (o->flag != 0) {
        i = 0;
        if (o->n - 1 > 0) {
            do {
                f32 a = t[i];
                i++;
                f32 b;
                if (i < o->n - 1) b = t[i]; else b = t[4];
                func_003F5758(o->p[i], o->p[i + 1], o->x1c, o->x20 + a * d, o->x24, o->x20 + b * d);
            } while (i < o->n - 1);
        }
    
    } else {
        i = 0;
        if (o->n != 0) {
            do {
                func_00477DC0(o->p[i]);
                f32 a = t[i];
                i++;
                f32 b;
                if (i < o->n) b = t[i]; else b = t[4];
                func_003F56C0(o->x1c, o->x20 + a * d, o->x24, o->x20 + b * d);
            } while (i < o->n);
        }
    }
}
