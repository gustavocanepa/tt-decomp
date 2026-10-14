typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern char D_00583868[];

struct func_002F4E60_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

struct func_002F4E60_src {
    char pad0[0xCC];
    u8 unkCC;
    char padCD[3];
    u8 unkD0;
    u8 unkD1;
    u8 unkD2;
    u8 unkD3;
    u8 unkD4;
    u8 unkD5;
    u8 unkD6;
    u8 unkD7;
    u8 unkD8;
};

extern "C" void func_002F4E60(struct func_002F4E60_arg0 *arg0) {
    struct func_002F4E60_src *s;
    f32 t0;
    f32 t1;
    f32 t2;

    s = (struct func_002F4E60_src *)D_00583868;
    if (s->unkCC == 0) {
        arg0->unk4 = (f32)s->unkD1 * 0x1.0624DCp-10f;
        arg0->unk0 = -(f32)((s32)s->unkD0 * 100000);
        t0 = (f32)((s32)s->unkD2 * 100000);
        arg0->unk8 = t0;
        t1 = (f32)((s32)s->unkD3 * 100000);
        arg0->unkC = t1;
        t1 = t1 + t0;
        t2 = (f32)s->unkD4;
        arg0->unkC = t1;
        arg0->unk10 = t2 * 0x1.0624DCp-10f;
        arg0->unk18 = (f32)s->unkD6 * 0x1.0624DCp-10f;
        arg0->unk14 = -(f32)((s32)s->unkD5 * 100000) * 0.5f;
        arg0->unk1C = (f32)((s32)s->unkD7 * 100000);
        arg0->unk20 = (f32)((s32)s->unkD8 * 100000);
        s->unkCC = 1;
    }
}
