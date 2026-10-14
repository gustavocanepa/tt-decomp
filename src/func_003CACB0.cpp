/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Obj {
    s32 a;
    char pad[4];
    f32 r;
    f32 g;
    f32 b;
    f32 len;
};

extern "C" int func_0040D610(void *, int);

extern "C" void func_003CACB0(Obj *o, void *p, s32 q) {
    u32 c = func_0040D610(p, q);
    f32 r = (f32)(c & 0xFF) / 255.0f;
    f32 g = (f32)((c >> 8) & 0xFF) / 255.0f;
    f32 b = (f32)((c >> 16) & 0xFF) / 255.0f;
    f32 len;
    __asm__("sqrt.s %0, %1" : "=f"(len) : "f"(r * r + g * g + b * b));
    if (len == 0.0f) {
        len = 1.0f;
    }
    o->a = q;
    o->len = len;
    g /= len;
    b /= len;
    r /= len;
    o->r = r;
    o->g = g;
    o->b = b;
}
