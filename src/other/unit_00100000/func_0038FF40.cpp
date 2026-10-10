typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" s32 func_004660A0(f32 arg0, f32 arg1);

extern "C" u32 func_0038FF40(f32 fparg0) {
    return func_004660A0(fparg0 + fparg0, 10.0f) != 0;
}
