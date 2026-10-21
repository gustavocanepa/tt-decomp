/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { long ticks; int a, b, c, d; };
extern State D_007740C0;
extern "C" int func_005038D8(void);
extern "C" float __floatdisf(long);
extern "C" float func_004B5F48(int *a, int *b, int *c) {
    int enabled = func_005038D8();
    if (a) *a = D_007740C0.a;
    if (b) *b = D_007740C0.c;
    if (c) *c = D_007740C0.d;
    float result = __floatdisf(D_007740C0.ticks) / 1000000.0f;
    if (enabled) __asm__ volatile("ei");
    return result;
}
