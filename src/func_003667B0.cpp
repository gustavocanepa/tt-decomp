typedef int s32;
typedef float f32;

extern "C" char *func_00342620(s32);
extern "C" void func_004A6328(f32 *, f32 *, f32);

extern "C" void func_003667B0(s32 a0, f32 *arg1, f32 *arg2, f32 *arg3, f32 fparg0) {
    f32 sp[2];
    char *o = func_00342620(a0);
    func_004A6328(&sp[0], &sp[1], fparg0);
    f32 cosv = sp[1];
    f32 sinv = sp[0];
    f32 t5 = *(f32 *)(o + 0x7C);
    f32 t1 = *(f32 *)(o + 0x80);
    f32 t3 = -*(f32 *)(o + 0x84);
    f32 n5 = -t5;
    *arg1 = (n5 + t5) * *(f32 *)(o + 0x78);
    *arg2 = (((t1 * cosv) - (t3 * sinv)) - *(f32 *)(o + 0x80)) * *(f32 *)(o + 0x78);
    *arg3 = ((t1 * sinv) + (t3 * cosv) + *(f32 *)(o + 0x84)) * *(f32 *)(o + 0x78);
}
