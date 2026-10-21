typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

struct TempV0 {
    char pad0[0x1];
    u8 unk1;
};

struct Glob {
    char pad0[0xB6];
    u8 unkB6;
    u8 unkB7;
};

struct Elem {
    char pad0[0x3C];
    f32 unk3C;
    char pad40[0x4];
    s8 unk44;
    s8 unk45;
    char pad46[0x6];
    f32 unk4C;
    char pad50[0x4];
    f32 unk54;
    char pad58[0x18];
    f32 unk70;
    f32 unk74;
    char pad78[0x4];
    f32 unk7C;
    f32 unk80;
};

extern char D_00583868[];
extern "C" void *func_002FD378(s32 arg0);

extern "C" void func_002F62C0(void *arg0) {
    struct Obj *self;
    struct TempV0 *temp_v0;
    struct Glob *g;
    struct Elem *e;
    u32 i;
    f32 f0, f1, f2, f3;

    self = (struct Obj *)arg0;
    temp_v0 = (struct TempV0 *)func_002FD378(self->unk10);
    i = 0;
    if (temp_v0->unk1 != 0) {
        e = (struct Elem *)((char *)self + 0x164);
        g = (struct Glob *)D_00583868;
        do {
            f1 = e->unk54 * e->unk4C;
            if (e->unk45 < 0) {
                f1 = -f1;
            }
            f0 = e->unk3C * f1;
            if (e->unk44 > 0) {
                f3 = 0.0f;
                f2 = f1;
                f1 = f3;
            } else {
                f2 = 0.0f;
                f3 = f1;
                f1 = f0;
                f0 = f2;
            }
            e->unk7C = f0;
            e->unk80 = f1;
            if (g->unkB6 == 2) {
                e->unk74 = f1;
            } else {
                e->unk74 = f3;
            }
            if (g->unkB7 == 2) {
                e->unk70 = f0;
            } else {
                e->unk70 = f2;
            }
            i += 1;
            e = (struct Elem *)((char *)e + 0xF4);
        } while (i < temp_v0->unk1);
    }
}
