typedef int s32;
typedef float f32;

extern "C" void func_00472E80(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 *t3);
extern "C" void func_00473178(s32 arg0);
extern "C" void func_004752F8(f32 *arg0);

extern "C" void func_002C9EA8(void *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    f32 m[16];
    f32 temp_f20;
    s32 *temp_s0;

    temp_s0 = *(s32 **)((char *)arg0 + 0x327A0);
    temp_f20 = 1.0f;
    func_00472E80(arg1[0], 0x30, arg1[2], arg2, arg3, 8, 4, temp_s0);
    temp_f20 = temp_f20 - ((f32)(*temp_s0 & 0xFFFFFF) * 0x1p-23f);
    func_00473178(1);
    func_004752F8(m);
    func_00473178(0);
    *(f32 *)((char *)arg0 + 0x327A4) = m[14] / (temp_f20 + m[10]);
}
