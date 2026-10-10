/* The callees are declared throw(): the original translation unit defined them above this
 * function, which marks them nothrow for g++ 2.96 and lets reorg fill the branch delay slots
 * across their calls (knowledge/ee-gcc-2.96.md, "throw() on the declarations"). */
typedef signed char s8; typedef unsigned char u8; typedef int s32; typedef float f32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

extern "C" void func_00104C88(s32) throw();
extern "C" void func_003592C8(void *) throw();
extern "C" void func_0035A6B8(void *) throw();
extern "C" void func_0035A9D0(void *) throw();
extern "C" void func_0035AB30(void *, s32) throw();
extern "C" void func_0035B360(void *, s32) throw();
extern "C" void func_0035BDB0(void *) throw();
extern "C" void func_0035BF60(void *) throw();
extern "C" void func_0035C280(void *) throw();
extern "C" void func_0035C4B0(void *) throw();
extern "C" void func_0035D400(void) throw();
extern "C" void func_00360418(void *) throw();
extern "C" void func_0039ED80(void *, s32) throw();
extern "C" void func_0035CA28(char *arg0, s32 arg1) {
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
    if (M2C_FIELD(temp_s2, s32 *, 0x10) == 0) {
        func_0035D400();
    }
    temp_s0 = arg0 + 0x4C;
    func_00104C88(arg1);
    temp_s3 = arg0 + 0x84;
    temp_s4 = arg0 + 0xD4;
    M2C_FIELD(temp_s2, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    M2C_FIELD(temp_s0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    M2C_FIELD(temp_s3, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    M2C_FIELD(temp_s4, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    func_0035A6B8(temp_s2);
    func_003592C8(temp_s0);
    if (M2C_FIELD(arg0, u8 *, 0x19) != 0) {
        if (M2C_FIELD(arg0, u8 *, 0x1B) != 0) {
            func_0035AB30(temp_s3, arg1);
        }
        func_0035B360(temp_s4, arg1);
    }
    if (M2C_FIELD(arg0, u8 *, 0x18) == 0) {
        temp_v0 = arg0 + 0xAC;
        sp0 = temp_v0;
        temp_a0 = arg0 + 0x104;
        M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        temp_v0_2 = arg0 + 0x328;
        temp_s0_2 = arg0 + 0x128;
        temp_s2_2 = arg0 + 0x160;
        temp_s4_2 = arg0 + 0x1B8;
        temp_s6 = arg0 + 0x1F4;
        temp_s3_2 = arg0 + 0x274;
        M2C_FIELD(temp_a0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        temp_s7 = arg0 + 0x2A0;
        sp4 = temp_v0_2;
        temp_fp = arg0 + 0x2E4;
        M2C_FIELD(temp_s0_2, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_s2_2, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_s4_2, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_s6, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_s3_2, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_s7, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_fp, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_v0_2, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        func_0039ED80(temp_a0, arg1);
        func_0035BF60(temp_s0_2);
        if (M2C_FIELD(arg0, u8 *, 0x160) != 0) {
            func_0035C280(temp_s2_2);
        }
        func_0035C4B0(temp_s4_2);
        func_0035A9D0(temp_s6);
        if ((M2C_FIELD(arg0, u8 *, 0x274)) && (M2C_FIELD(arg0, u8 *, 0x36C) == 0)) {
            func_00360418(temp_s3_2);
        }
        if (M2C_FIELD(arg0, u8 *, 0x19) != 0) {
            if (M2C_FIELD(arg0, u8 *, 0x1C) != 0) {
                func_0035AB30(sp0, arg1);
            }
            func_0035BDB0(temp_s7);
            func_0035BDB0(temp_fp);
            func_0035BDB0(sp4);
        }
    }
}
