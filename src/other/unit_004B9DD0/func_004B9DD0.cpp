/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern "C" void func_004B7A28(s32, s32, s32, s32, s32, s32, s32, s32);

extern "C" void func_004B9DD0(s32 a, s32 b, s32 c, s32 d, s32 e) {
    func_004B7A28(6, a, b, c, 0, 0, d, e);
}
