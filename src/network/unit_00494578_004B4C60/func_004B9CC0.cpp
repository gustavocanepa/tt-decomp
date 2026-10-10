/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern "C" void func_004B7A28(s32, s32, s32, s32, s32, s32, s32, s32);

extern "C" void func_004B9CC0(s32 a, s32 b, s32 c, s32 d) {
    func_004B7A28(3, a, b, 0, 0, 0, c, d);
}
