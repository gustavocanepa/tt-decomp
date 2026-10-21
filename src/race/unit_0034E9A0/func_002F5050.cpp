/* compiler: ee-gcc2.96-no-strict-aliasing */
struct A { float m0, m4, m8, mC, m10, m14, m18, m1C, m20; };
struct B { char p0[4]; float m4, m8; char pc[8]; unsigned char m14; };
extern "C" void func_002F4E60(float *) throw();
extern "C" float func_002F5050(A *a, B *b)
{
    if (b->m14 != 0) return 1.0f;
    {
        func_002F4E60((float *)a);
        float x = b->m4;
        float f4 = 1.0f;
        float v;
        if (x < a->m0) {
            v = a->m4;
            f4 -= v;
        } else if (x < 0.0f) {
            v = x * a->m4 / a->m0;
            f4 -= v;
        } else if (!(x <= a->m8)) {
            if (x < a->mC) {
                v = (x - a->m8) * a->m10 / (a->mC - a->m8);
                f4 -= v;
            } else {
                v = a->m10;
                f4 -= v;
            }
        }
        float y = b->m8;
        float f3 = 1.0f;
        if (y < a->m14) {
            f3 = a->m18 + 1.0f;
        } else if (y < 0.0f) {
            f3 = y * a->m18 / a->m14 + 1.0f;
        } else if (a->m20 < y) {
            float t = (y - a->m20) / (a->m1C - a->m20);
            if (t > 1.0f) t = 1.0f;
            f3 = 1.0f - a->m18 * t;
        }
        return f4 * f3;
    }
}
