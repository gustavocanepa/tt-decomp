typedef int s32;

extern "C" s32 func_00403E90(s32 arg0);
extern "C" s32 func_004041F8(s32 arg0, s32 arg1);
extern "C" s32 func_004045F8(s32 arg0, s32 arg1);
extern "C" s32 func_00404A60(s32 arg0, s32 arg1);

extern "C" s32 func_00403420(s32 arg0) {
    s32 s0 = arg0;
    s32 v0;

    v0 = func_00403E90(s0 + 0x18);
    v0 = func_004041F8(s0 + 0x48, v0);
    v0 = func_004045F8(s0 + 0x64, v0);
    return func_00404A60(s0 + 0x8C, v0);
}
