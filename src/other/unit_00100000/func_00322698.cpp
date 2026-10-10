typedef int s32;
typedef float f32;

struct Info_00379AA8 {
    char pad0[0x14];
    f32 m14;
    char pad18[0x28];
};

extern "C" void func_004752F8(Info_00379AA8 *info);
extern "C" f32 func_004A6008(f32 x);
extern "C" void func_00472268(s32 id, s32 value);
extern "C" f32 D_00585D04;

extern "C" void func_00322698(void) {
    Info_00379AA8 info;
    func_004752F8(&info);
    func_00472268(10, (s32)((-func_004A6008(info.m14) * 0x1.715476p+0f + D_00585D04) * 256.0f));
}
