/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" unsigned int func_0038F5F8(unsigned int color, float scale) {
    float a = (float)((color >> 24) & 0xFF);
    color &= 0xFFFFFF;
    a = minf(maxf(a * scale, 0.0f), 255.0f);
    return ((int)a << 24) | color;
}
