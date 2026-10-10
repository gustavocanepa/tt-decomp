typedef float f32;

extern "C" f32 func_004A5A68(f32 arg0);

extern "C" f32 func_00389690(f32 arg0) {
    f32 t = 1.0f - arg0 * arg0;
    __asm__("sqrt.s %0, %1" : "=f"(t) : "f"(t));
    return func_004A5A68(arg0 / t);
}
