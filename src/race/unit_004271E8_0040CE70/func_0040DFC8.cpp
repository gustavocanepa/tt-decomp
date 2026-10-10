typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Info {
    char pad0[0xE];
    u8 unkE;
    char padF[0x11];
};

struct Global;

struct Obj {
    char pad0[0x40];
    s64 id;
};

extern Global D_00585A30;

extern "C" void func_0040B910(Global *g, s64 id, Info *info);

extern "C" s32 func_0040DFC8(Obj *self) {
    s64 id = self->id;
    if (id == -1) {
        return -1;
    }
    Info info;
    func_0040B910(&D_00585A30, id, &info);
    return info.unkE;
}
