typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct Sub003683C8 {
    s32 unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
};

extern "C" s32 func_00310520(void *arg0);
extern "C" void func_003103D8(void *arg0);

extern "C" void func_00310540(void *arg0) {
    struct Sub003683C8 *temp_v1;

    if (func_00310520(arg0) != 0) {
        temp_v1 = (struct Sub003683C8 *)((char *)arg0 + 0x7E4);
        temp_v1->unk4 = 1.0f;
        temp_v1->unk0 = 0;
        temp_v1->unk8 = 0;
        temp_v1->unk9 = 0;
        return func_003103D8(arg0);
    }
}
