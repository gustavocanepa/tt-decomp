typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Info {
    char pad0[0x2];
    u8 unk2;
    char pad3[0x1D];
};

struct Global;

struct Obj {
    char pad0[0xE0];
    s64 id;
};

extern Global D_00585A30;

extern "C" void func_0040B910(Global *g, s64 id, Info *info);

extern "C" s32 func_0040E088(Obj *self) {
    s64 id = self->id;
    if (id == -1) {
        return -1;
    }
    Info info;
    func_0040B910(&D_00585A30, id, &info);
    return info.unk2;
}
