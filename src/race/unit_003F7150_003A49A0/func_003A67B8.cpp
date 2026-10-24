/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cam { char pad[0x40]; float f40; float n; float f; float f4C; };
extern "C" void func_00475440(void *);
static inline float &element(float *m, int x, int y) { return m[y * 4 + x]; }
extern "C" void func_003A67B8(Cam *c, int flag)
{
    float m[16];
    float n = c->n;
    float f = c->f;
    float sum = f + n;
    float d = f - n;
    
    element(m, 0, 0) = 1.0f; element(m, 0, 1) = 0; element(m, 0, 2) = 0; element(m, 0, 3) = 0;
    element(m, 1, 0) = 0; element(m, 1, 1) = 1.0f;
    element(m, 1, 2) = 0;
    element(m, 1, 3) = 0;
    element(m, 2, 0) = 0;
    element(m, 2, 1) = 0;
    element(m, 3, 0) = 0; element(m, 3, 1) = 0; element(m, 3, 2) = -1.0f; element(m, 3, 3) = 0;
    element(m, 2, 2) = -sum / d;
    element(m, 2, 3) = -(2.0f * f * n) / d;
    func_00475440(m);
    func_00475440(c);
    float v = c->f4C * c->f40;
    if (flag == 0) v = c->f4C;
    element(m, 0, 0) = v;
    element(m, 0, 1) = 0; element(m, 0, 2) = 0; element(m, 0, 3) = 0;
    element(m, 1, 0) = 0; element(m, 1, 1) = v; element(m, 1, 2) = 0; element(m, 1, 3) = 0;
    element(m, 2, 0) = 0; element(m, 2, 1) = 0; element(m, 2, 2) = 1.0f; element(m, 2, 3) = 0;
    element(m, 3, 0) = 0; element(m, 3, 1) = 0; element(m, 3, 2) = 0; element(m, 3, 3) = 1.0f;
    func_00475440(m);
}
