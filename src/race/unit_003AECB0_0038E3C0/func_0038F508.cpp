typedef int s32;
typedef float f32;

extern s32 D_00579518;

extern "C" f32 func_0038F508(s32 flags) {
    f32 v;
    if (!(flags & 4))
        return 0.0f;
    v = 96.0f;
    if (D_00579518 == 0)
        v = 0.0f;
    if (flags & 8)
        return v;
    return -v;
}
