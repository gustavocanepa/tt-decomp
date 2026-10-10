typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
typedef int s128 __attribute__((mode(TI))); typedef unsigned int u128 __attribute__((mode(TI)));

s32 func_00464C28();
void func_00465F48(s32, s32, f32, f32, f32);
void func_00465F98(s32, s32, f32, f32, f32, f32);
void func_0046F0F8(s32);
void func_004702D8(s32, f32);
void func_00470478(s32);
void func_00473050();
void func_004730A8();
void func_004751FC();
void func_004755EC(f32, f32, f32);
void func_00475638(f32, f32, f32);
void func_00478C98(s32);

void func_00466198(s32 arg0, s32 arg1, f32 *arg2, s32 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6, f32 fparg7) {
    f32 z;
    f32 s;
    s32 shadow;
    s32 lit = arg1 & 1;
    s32 tex;

    shadow = 0;
    z = -arg2[2];
    if (fparg6 > 0.0f && fparg7 > 0.0f && z > 1.0f) {
        shadow = 1;
    }
    s = (z - fparg0) / z;
    tex = arg1 & 2;
    func_00470478(0);
    func_0046F0F8(6);
    func_004702D8(0x48, 0.0f);
    func_004751FC();
    func_004755EC(arg2[0] * s, arg2[1] * s, arg2[2] * s);
    if (lit) {
        func_00473050();
        func_00475638(fparg5, fparg5, fparg5);
        if (tex) {
            func_0046F0F8(5);
            func_00465F98(arg0, arg3, fparg1, fparg2, fparg3, fparg4);
        } else {
            func_00478C98(5);
            func_00465F48(arg0, arg3, fparg1 * fparg4, fparg2 * fparg4, fparg3 * fparg4);
        }
        func_004730A8();
    }
    if (shadow != 0) {
        func_00475638(fparg7, fparg7, fparg7);
        func_0046F0F8(5);
        func_00465F98(arg0, func_00464C28(), fparg1, fparg2, fparg3, fparg6);
    }
    func_00470478(1);
}
