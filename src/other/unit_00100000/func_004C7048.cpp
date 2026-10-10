/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef float f32;

extern "C" f32 D_005A0498;
extern "C" u32 D_005A049C;

extern "C" f32 func_004C7048(f32 v) {
    f32 old = D_005A0498;
    D_005A0498 = v;
    D_005A049C = (u32)(v * 127.0f);
    return old;
}
