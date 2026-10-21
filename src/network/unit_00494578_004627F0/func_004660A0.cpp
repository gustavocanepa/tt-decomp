extern "C" void func_00465C48(void *, int, float, float, float, float);
extern "C" void func_00474BC8(float);
struct Vec { float x, y, z; };
struct S { char pad[0x10]; int f10; int f14; };
extern "C" void func_004660A0(S *self, Vec *v, float a, float b) {
    float fx = (v->x * 0.5f + 0.5f) * (float)self->f10;
    float fy = (0.5f - v->y * 0.5f) * (float)self->f14;
    float z = b;
    float t = v->z - 0.2f;
    if (t < 0.0f) t = 0.0f;
    func_00474BC8(t);
    if (z < 2.0f) z = 2.0f;
    int n = (int)z;
    func_00465C48(self, 0, fx, fy, z, a / (float)(n * n));
}
