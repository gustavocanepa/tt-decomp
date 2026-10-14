/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
struct Obj {
    char pad0[0x18];
    float unk18;
};
extern Obj D_00585CC8;
struct Self {
    char pad0[1];
    u8 unk1;
    char pad2[2];
    s16 unk4;
    s16 unk6;
    char pad8[4];
    float unkC;
    char pad10[8];
    s32 unk18;
    float unk1C;
    char unk20[1];
};
extern "C" float func_0038F448(int a, float x, float w);
extern "C" s32 func_0038F5F8(s32 a, float f);
extern "C" void func_00415510(void *o, const char *s);
extern "C" void func_00415578(void *o);
extern "C" void func_00415A10(void *o, float x, float y, float z);
extern "C" void func_00415B10(void *o, s32 v);
extern "C" float func_00415C58(void *o, void *b);
extern "C" void func_00415CC0(void *self, void *item);
extern "C" void func_004A6500(void *buf, const char *fmt, ...);

extern "C" void RaceOdometer__render_main(Self *arg0) {
    char buf[0x20];
    float f;
    func_00415510(&D_00585CC8, "GT4oddmeter#1");
    func_00415B10(&D_00585CC8, func_0038F5F8(0x80E3B896, arg0->unkC));
    func_004A6500(buf, arg0->unk20, arg0->unk18);
    f = arg0->unk1C;
    if (f == 0.0f) {
        float t = func_00415C58(&D_00585CC8, buf) / D_00585CC8.unk18;
        arg0->unk1C = t;
        f = t;
    }
    func_00415A10(&D_00585CC8, func_0038F448(arg0->unk1, (float)arg0->unk4, f), (float)arg0->unk6, 0.0f);
    func_00415CC0(&D_00585CC8, buf);
    func_00415578(&D_00585CC8);
}
