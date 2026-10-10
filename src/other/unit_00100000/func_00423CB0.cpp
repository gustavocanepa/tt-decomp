typedef int s32;
typedef unsigned char u8;
typedef float f32;

extern "C" void func_00423D40(s32 arg0, u8 *arg1, s32 arg2);

extern "C" void func_00423CB0(s32 arg0, f32 arg1) {
    f32 buf = arg1;
    func_00423D40(arg0, (u8 *)&buf, 4);
}
