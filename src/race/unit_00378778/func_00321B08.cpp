/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef short s16; typedef signed char s8; typedef unsigned char u8; typedef long long s64; typedef float f32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
struct V50 { s16 delta, index; s32 (*fn)(void *,void *,s32,s32,s32,s32); };
struct V60 { s16 delta, index; void (*fn)(void *); };
struct V90 { s16 delta, index; f32 (*fn)(void *,s32); };
extern "C" s32 func_003175C0(s32);
extern "C" s32 func_003A91E8(void *, void *, void *);
extern "C" void func_0046E150();
extern "C" void func_0046E1B0();
extern "C" void func_00473050();
extern "C" void func_004730A8();
extern "C" void func_0047525C(void *);
extern "C" void func_004757FC();
extern "C" void func_00475850(void *, void *);
extern "C" f32 func_004A5DE0(f32);
extern "C" void func_00552A68(void *, void *);
static inline s64 set24(s64 word, s64 value) { return (word & 0xFFFFFFFF00FFFFFFLL) | (value << 24); }
static inline void init(f32 *p, f32 *y, f32 *z, f32 a, f32 b, f32 c, f32 d) { *z=c; *y=b; p[0]=a; p[3]=d; }
extern "C"
void func_00321B08(char *arg0, char *arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct StackFrame_00378F28 { f32 sp0; f32 sp4; f32 sp8; f32 spC; s32 sp10; s8 pad0[0xC]; s32 sp20; s8 pad1[0xC]; } sp_;
    void *temp_a1;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 temp_a1_2;
    s32 temp_s2;
    s32 temp_s4;
    s32 temp_v1;
    s32 var_s1;
    s32 var_s1_2;
    char *temp_s0;
    void *temp_a0;
    char *temp_a0_2;
    char *temp_a1_3;
    char *temp_a2;
    char *temp_fp;
    char *temp_s0_2;
    void *temp_s5;
    char *temp_v0;
    char *temp_v0_2;
    char *var_s0;

    temp_s4 = M2C_FIELD(arg0, s32 *, 0x140) == 0;
    for (var_s1 = 1; var_s1 > 0; var_s1--) {
        var_s0 = arg0 + var_s1 * 0x6C;
        M2C_FIELD(var_s0, f32 *, 4) = (f32) M2C_FIELD(var_s0, f32 *, -0x68);
        M2C_FIELD(var_s0, f32 *, 8) = (f32) M2C_FIELD(var_s0, f32 *, -0x64);
        M2C_FIELD(var_s0, f32 *, 0xC) = (f32) M2C_FIELD(var_s0, f32 *, -0x60);
        func_00552A68(var_s0 - 0x5C, var_s0 + 0x10);
        M2C_FIELD(var_s0, f32 *, 0x1C) = (f32) M2C_FIELD(var_s0, f32 *, -0x50);
        M2C_FIELD(var_s0, f32 *, 0x20) = (f32) M2C_FIELD(var_s0, f32 *, -0x4C);
        M2C_FIELD(var_s0, f32 *, 0x24) = (f32) M2C_FIELD(var_s0, f32 *, -0x48);
        func_00552A68(var_s0 - 0x44, var_s0 + 0x28);
        func_00552A68(var_s0 - 0x38, var_s0 + 0x34);
        func_00552A68(var_s0 - 0x2C, var_s0 + 0x40);
        func_00552A68(var_s0 - 0x20, var_s0 + 0x4C);
        func_00552A68(var_s0 - 0x14, var_s0 + 0x58);
        temp_a0 = var_s0 - 8;
        temp_a1 = var_s0 + 0x64;
        func_00552A68(temp_a0, temp_a1);
    }
    temp_a1_2 = M2C_FIELD(arg0, s32 *, 0x140);
    if (temp_a1_2 != 0) {
        M2C_FIELD(arg0, s64 *, 0x168) = set24(M2C_FIELD(arg0, s64 *, 0x168), 1);
    }
    temp_s5 = arg0 + 0x10;
    M2C_FIELD(arg0, s32 *, 0x140) = func_003175C0(temp_a1_2);
    M2C_FIELD(arg0, s32 *, 0x144) = func_003175C0(M2C_FIELD(arg0, s32 *, 0x144));
    M2C_FIELD(arg0, s64 *, 0x168) = (s64) (M2C_FIELD(arg0, s64 *, 0x168) & ((((-0x100LL << 0x10) | 0xFFFF) << 0x10) | 0xFFFF));
    temp_a1_3 = M2C_FIELD(arg0, char **, 0);
    V50 *e50 = (V50 *)(temp_a1_3 + 0x50);
    sp_.sp20 = e50->fn(arg0 + e50->delta, arg1, arg2, arg3, arg4, 1);
    if (temp_s4) sp_.sp20 = 0;
    func_0046E150();
    func_00473050();
    func_0047525C(arg0 + 0x100);
    func_004757FC();
    f32 *p4 = &sp_.sp4;
    f32 *p8 = &sp_.sp8;
    init(&sp_.sp0, p4, p8, 0.0f, 0.0f, 0.0f, 1.0f);
    func_00475850(((s8 *)&sp_), ((s8 *)&sp_));
    M2C_FIELD(temp_s5, f32 *, 0) = sp_.sp0;
    M2C_FIELD(arg0, f32 *, 0x14) = *p4;
    M2C_FIELD(arg0, f32 *, 0x18) = *p8;
    func_004730A8();
    func_0046E1B0();
    V60 *e60 = (V60 *)(M2C_FIELD(arg0, char **, 0) + 0x60);
    e60->fn(arg0 + e60->delta);
    if (M2C_FIELD(arg0, u8 *, 0x16A) != 0) {
        temp_v0_2 = M2C_FIELD(arg0, char **, 0);
        temp_a2 = M2C_FIELD(arg1, char **, 0x60);
        void *p10 = &sp_.sp10;
        var_s1_2 = 0;
        temp_s2 = M2C_FIELD(temp_a2, s32 *, 0);
        V90 *e90 = (V90 *)(temp_v0_2 + 0x90);
        temp_f20 = e90->fn(arg0 + e90->delta, arg4);
        temp_f20_2 = temp_f20 + (temp_f20 * func_004A5DE0((M2C_FIELD(arg0, f32 *, 0xC) * 0x1.0000000000000p-1f * 0x1.921fb40000000p+1f) / 0x1.6800000000000p+7f));
        sp_.sp0 = temp_f20_2;
        *p4 = temp_f20_2 + 0x1.9999980000000p-3f;
        *p8 = temp_f20_2;
        func_00552A68(temp_s5, p10);
        if (temp_s2 > 0) {
            arg4 = (s32)(arg0 + 4);
            do {
                temp_v1 = var_s1_2 * 4;
                var_s1_2 += 1;
                temp_a0_2 = *(char * *)(temp_v1 + M2C_FIELD(M2C_FIELD(arg1, char **, 0x60), s32 *, 8));
                s32 idx = M2C_FIELD(temp_a0_2, s32 *, 0x14) + 0x160;
                temp_s0 = (char *)arg4 + idx;
                *temp_s0 = 0;
                if (func_003A91E8(temp_a0_2, p10, ((s8 *)&sp_)) != 0) {
                    *temp_s0 = 1;
                }
            } while (var_s1_2 < temp_s2);
        }
    }
    if (sp_.sp20 == 0) {
        arg4 = (s32)(arg0 + 4);
        temp_s0_2 = arg0 + 0x6C;
        char *p28=arg0+0x28, *p34=arg0+0x34, *p40=arg0+0x40, *p4c=arg0+0x4c, *p58=arg0+0x58, *p64=arg0+0x64;
        M2C_FIELD(temp_s0_2, f32 *, 4) = (f32) M2C_FIELD((char *)arg4, f32 *, 0);
        M2C_FIELD(temp_s0_2, f32 *, 8) = (f32) M2C_FIELD((char *)arg4, f32 *, 4);
        M2C_FIELD(temp_s0_2, f32 *, 0xC) = (f32) M2C_FIELD((char *)arg4, f32 *, 8);
        func_00552A68(temp_s5, arg0 + 0x7C);
        M2C_FIELD(temp_s0_2, f32 *, 0x1C) = (f32) M2C_FIELD((char *)arg4, f32 *, 0x18);
        M2C_FIELD(temp_s0_2, f32 *, 0x20) = (f32) M2C_FIELD((char *)arg4, f32 *, 0x1C);
        M2C_FIELD(temp_s0_2, f32 *, 0x24) = (f32) M2C_FIELD((char *)arg4, f32 *, 0x20);
        func_00552A68(p28, arg0 + 0x94);
        func_00552A68(p34, arg0 + 0xA0);
        func_00552A68(p40, arg0 + 0xAC);
        func_00552A68(p4c, arg0 + 0xB8);
        func_00552A68(p58, arg0 + 0xC4);
        func_00552A68(p64, arg0 + 0xD0);
    }
}
