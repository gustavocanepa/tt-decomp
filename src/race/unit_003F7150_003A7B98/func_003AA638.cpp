static inline float absf(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct Obj { unsigned flags; char p0[8]; float c; float d10; float e14; float u18; char p1[4]; float u20; float u24; };
extern "C" void func_003AA620(Obj *, float *, float *) throw();

extern "C" void func_003AA638(Obj *o, float t)
{
    float s[2];
    o->u24 = 0.0f;
    if ((o->flags & 7) == 0) {
        if (t < o->u20) o->u24 = o->u24 - (o->u20 - t) * 0.5f;
        float g = o->u18;
        if (g > 0.0f) {
            if (t < g) o->u24 = o->u24 - (g - t) * 4.0f;
        } else {
            o->u24 = o->u24 - 2.0f * -g;
        }
        float z = 0.0f;
        func_003AA620(o, &s[0], &s[1]);
        float m = o->d10;
        float a = m - s[0];
        float b = s[1] - m;
        s[0] = a;
        s[1] = b;
        if (a <= 0.01f) s[0] = 0.01f;
        if (b <= 0.01f) s[1] = 0.01f;
        float c = o->c;
        float x = m - c;
        float zero = z;
        if (x < z) x = z;
        z = (c + t * o->e14) - m;
        if (z < zero) z = zero;
        x /= s[0];
        z /= s[1];
        if (x > 1.0f) o->u24 = o->u24 - (x - 1.0f);
        if (z > 1.0f) o->u24 = o->u24 - (z - 1.0f) * 0x1.555554p-2f;
        o->u24 -= absf(x - z) * 3.0f;
    }
}
