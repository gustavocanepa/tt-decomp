typedef int s32;
typedef float f32;
typedef unsigned char u8;
typedef signed char s8;

extern s8 D_00582CB0[];
extern u8 D_00582CB8[];
extern u8 D_00582CC0[];
extern s8 D_00582CC8[];
extern s8 D_00582CD0[];
extern f32 D_00582CD8[];
extern f32 D_00582CF0[];
extern f32 D_00582D08[];

extern "C" void func_002E3E80(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        D_00582CD0[i] = (s8)((((s32)D_00582CB0[i] << 7) + 0x3200) / 100);
        D_00582CD8[i] = (f32)D_00582CB8[i] / 100.0f;
        D_00582CF0[i] = (f32)D_00582CC0[i] / 100.0f;
        D_00582D08[i] = (f32)(D_00582CC8[i] + 100) / 100.0f;
    }
}
