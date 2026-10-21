/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Obj {
    char pad0[8];
    f32 r0;
    f32 r1;
    f32 r2;
    f32 f14;
    f32 f18;
    f32 f1c;
    f32 a[3];
    f32 b[3];
    s32 z38;
    f32 one;
    s32 z40;
    s32 z44;
    f32 alpha;
    char *p4c;
};

extern "C" u8 GT4Model__BinStreamReader__read8u(s32 s);
extern "C" f32 GT4Model__BinStreamReader__readFloat(s32 s);

extern "C" void func_003CE228(Obj *o, s32 s, char *base) {
    s32 i;
    o->p4c = base + GT4Model__BinStreamReader__read8u(s) * 0x74 + 0xC;
    o->r0 = (f32)GT4Model__BinStreamReader__read8u(s) * 0x1.921fb4p+1f * 0.0078125f;
    o->r1 = (f32)GT4Model__BinStreamReader__read8u(s) * 0x1.921fb4p+1f * 0.0078125f;
    o->r2 = (f32)GT4Model__BinStreamReader__read8u(s) * 0x1.921fb4p+1f * 0.0078125f;
    o->f14 = GT4Model__BinStreamReader__readFloat(s);
    o->f18 = GT4Model__BinStreamReader__readFloat(s);
    o->f1c = GT4Model__BinStreamReader__readFloat(s);
    o->alpha = (f32)GT4Model__BinStreamReader__read8u(s) / 255.0f;
    o->z38 = 0;
    o->one = 1.0f;
    o->z40 = 0;
    o->z44 = 0;
    for (i = 0; i < 3; i++) {
        o->a[i] = 0;
        o->b[i] = 0;
    }
}
