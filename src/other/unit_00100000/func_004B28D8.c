/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef float f32;

u32 func_004B2850(void);

f32 func_004B28D8(void) {
    return (f32)func_004B2850() * 0x1.000000p-32f;
}
