typedef int s32;
typedef unsigned short u16;
typedef float f32;

struct Vec4 {
    f32 x, y, z, w;
};

struct Obj0042D528 {
    char pad0[0x14];
    u16 count;
    char pad1[0x18 - 0x16];
    s32 *unk18;
};

extern "C" void func_003F5190(s32 a, s32 b, f32 x, f32 y, f32 z);

extern "C" void func_003F4BB0(Obj0042D528 *arg0, s32 *arg1, f32 x, f32 y, f32 z) {
    s32 i;
    for (i = 0; i < arg0->count; i++) {
        s32 v0 = i * 4;
        s32 v1 = v0 + arg1[6];
        s32 a0 = *(s32 *)(v0 + (s32)arg0->unk18);
        func_003F5190(a0, *(s32 *)(v1), x, y, z);
    }
}
