/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef signed char s8;
struct S { char pad[5]; s8 v; };
extern float D_007673E0;
extern "C" void func_002F9B38(char *o, float f) {
    S *s = (S *)(o + 0x7E4);
    int v = s->v + (int)(f * D_007673E0);
    if (v > 100) v = 100;
    else if (v < -100) v = -100;
    s->v = v;
}
