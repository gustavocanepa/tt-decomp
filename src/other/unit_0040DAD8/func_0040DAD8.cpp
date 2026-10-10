typedef int s32;
typedef long long s64;

struct Info {
    s32 unk0[4];
    s32 unk10;
    char pad14[0x6C];
};

struct Global {
    char pad0[0x1E8];
    s32 unk1E0;
};

struct Obj {
    char pad0[0x38];
    s64 id;
};

extern Global D_00585A30;

extern "C" void func_0040B910(Global *g, s64 id, Info *info);
extern "C" void func_00411D78(s32 a, s32 b);

extern "C" void func_0040DAD8(Obj *self) {
    Info info;
    func_0040B910(&D_00585A30, self->id, &info);
    func_00411D78(D_00585A30.unk1E0, info.unk10);
}
