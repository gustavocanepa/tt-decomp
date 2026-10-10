/* The callees are declared throw(): the original translation unit defined them above this
 * function, which marks them nothrow for g++ 2.96 and lets reorg fill the branch delay slots
 * across their calls (knowledge/ee-gcc-2.96.md, "throw() on the declarations"). */
typedef signed char s8; typedef unsigned char u8; typedef int s32; typedef float f32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

extern "C" void func_00104C88(s32) throw();
extern "C" void RaceDigitalSpeedmeter__render_main(void *) throw();
extern "C" void func_0035A6B8(void *) throw();
extern "C" void RaceABMonitor__render_main(void *) throw();
extern "C" void RaceFuelMeter__render_main(void *, s32) throw();
extern "C" void RaceTireWearDisplay__render_main(void *, s32) throw();
extern "C" void RaceIndicator__render_main(void *) throw();
extern "C" void func_0035BF60(void *) throw();
extern "C" void func_0035C280(void *) throw();
extern "C" void func_0035C4B0(void *) throw();
extern "C" void func_0035D400(void) throw();
extern "C" void func_00360418(void *) throw();
extern "C" void RaceBattleTachometer__render_main(void *, s32) throw();
struct RaceSimplePanel__virtual_05_temp_s2 {
    char pad0[0xC];
    f32 unkC;
    s32 unk10;
};
struct RaceSimplePanel__virtual_05_arg0 {
    char pad0[0xC];
    f32 unkC;
    char pad10[0x8];
    u8 unk18;
    u8 unk19;
    char pad1A[0x1];
    u8 unk1B;
    u8 unk1C;
    char pad1D[0x143];
    u8 unk160;
    char pad161[0x113];
    u8 unk274;
    char pad275[0xF7];
    u8 unk36C;
};
struct RaceSimplePanel__virtual_05_temp_s0 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s3 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s4 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_v0 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_a0 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s0_2 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s2_2 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s4_2 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s6 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s3_2 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s7 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_fp {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_v0_2 {
    char pad0[0xC];
    f32 unkC;
};

extern "C" void RaceSimplePanel__render_main(char *arg0, s32 arg1) {
    char *sp0;
    char *sp4;
    char *temp_a0;
    char *temp_fp;
    char *temp_s0;
    char *temp_s0_2;
    char *temp_s2;
    char *temp_s2_2;
    char *temp_s3;
    char *temp_s3_2;
    char *temp_s4;
    char *temp_s4_2;
    char *temp_s6;
    char *temp_s7;
    char *temp_v0;
    char *temp_v0_2;
    temp_s2 = arg0 + 0x30;
    if (((struct RaceSimplePanel__virtual_05_temp_s2 *)temp_s2)->unk10 == 0) {
        func_0035D400();
    }
    temp_s0 = arg0 + 0x4C;
    func_00104C88(arg1);
    temp_s3 = arg0 + 0x84;
    temp_s4 = arg0 + 0xD4;
    ((struct RaceSimplePanel__virtual_05_temp_s2 *)temp_s2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
    ((struct RaceSimplePanel__virtual_05_temp_s0 *)temp_s0)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
    ((struct RaceSimplePanel__virtual_05_temp_s3 *)temp_s3)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
    ((struct RaceSimplePanel__virtual_05_temp_s4 *)temp_s4)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
    func_0035A6B8(temp_s2);
    RaceDigitalSpeedmeter__render_main(temp_s0);
    if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk19 != 0) {
        if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk1B != 0) {
            RaceFuelMeter__render_main(temp_s3, arg1);
        }
        RaceTireWearDisplay__render_main(temp_s4, arg1);
    }
    if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk18 == 0) {
        temp_v0 = arg0 + 0xAC;
        sp0 = temp_v0;
        temp_a0 = arg0 + 0x104;
        ((struct RaceSimplePanel__virtual_05_temp_v0 *)temp_v0)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        temp_v0_2 = arg0 + 0x328;
        temp_s0_2 = arg0 + 0x128;
        temp_s2_2 = arg0 + 0x160;
        temp_s4_2 = arg0 + 0x1B8;
        temp_s6 = arg0 + 0x1F4;
        temp_s3_2 = arg0 + 0x274;
        ((struct RaceSimplePanel__virtual_05_temp_a0 *)temp_a0)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        temp_s7 = arg0 + 0x2A0;
        sp4 = temp_v0_2;
        temp_fp = arg0 + 0x2E4;
        ((struct RaceSimplePanel__virtual_05_temp_s0_2 *)temp_s0_2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_s2_2 *)temp_s2_2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_s4_2 *)temp_s4_2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_s6 *)temp_s6)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_s3_2 *)temp_s3_2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_s7 *)temp_s7)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_fp *)temp_fp)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_v0_2 *)temp_v0_2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        RaceBattleTachometer__render_main(temp_a0, arg1);
        func_0035BF60(temp_s0_2);
        if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk160 != 0) {
            func_0035C280(temp_s2_2);
        }
        func_0035C4B0(temp_s4_2);
        RaceABMonitor__render_main(temp_s6);
        if ((((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk274) && (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk36C == 0)) {
            func_00360418(temp_s3_2);
        }
        if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk19 != 0) {
            if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk1C != 0) {
                RaceFuelMeter__render_main(sp0, arg1);
            }
            RaceIndicator__render_main(temp_s7);
            RaceIndicator__render_main(temp_fp);
            RaceIndicator__render_main(sp4);
        }
    }
}
