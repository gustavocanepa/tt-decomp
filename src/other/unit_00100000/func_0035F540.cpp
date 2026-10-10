typedef int s32;
typedef float f32;

extern "C" f32 func_0035F4A0(void **arg0, s32 *arg1);

extern "C" s32 func_0035F540(void **arg0, s32 *arg1) {
    return (s32)(func_0035F4A0(arg0, arg1) * 255.0f);
}
